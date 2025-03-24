#include <stdio.h>       // printf, perror 등 표준 입출력 함수
#include <stdlib.h>      // exit, malloc, free 등
#include <unistd.h>      // fork, execve 등 프로세스 관리 함수
#include <signal.h>      // signal, sigaction, sigprocmask 등 신호 처리 함수
#include <sys/types.h>   // pid_t 등 데이터 타입
#include <sys/wait.h>    // waitpid 함수
#include <errno.h>       // errno 변수 및 오류 처리 관련 매크로
#include <string.h>      // 문자열 처리 (에러 메시지 등)


void Sio_error(const char *msg) {
    write(STDERR_FILENO, msg, strlen(msg));
    _exit(1);
}


typedef struct job {
    pid_t pid;
    struct job *next;
} job_t;

job_t *job_list = NULL;

void initjobs() {
    job_list = NULL; // 초기화
}

void addjob(pid_t pid) {
    job_t *new_job = (job_t*)malloc(sizeof(job_t));
    new_job->pid = pid;
    new_job->next = job_list;
    job_list = new_job;
}

void deletejob(pid_t pid) {
    job_t *prev = NULL, *curr = job_list;

    while (curr != NULL && curr->pid != pid) {
        prev = curr;
        curr = curr->next;
    }
    if (curr != NULL) {
        if (prev == NULL) {
            job_list = curr->next;
        } else {
            prev->next = curr->next;
        }
        free(curr);
    }
}



void handler(int sig)
{
    int olderrno = errno;
    sigset_t mask_all, prev_all;
    pid_t pid;


    sigfillset(&mask_all);
    while ((pid = waitpid(-1, NULL, 0)) > 0)
    { /* Reap child */
        sigprocmask(SIG_BLOCK, &mask_all, &prev_all);
        deletejob(pid); /* Delete the child from the job list */
        sigprocmask(SIG_SETMASK, &prev_all, NULL);
    }
    if (errno != ECHILD)
        Sio_error("waitpid error");
    errno = olderrno;
}

int main(int argc, char **argv)
{
    int pid;
    sigset_t mask_all, prev_all, mask, prev_one;
    int n = 5; /* N = 5 */
    sigfillset(&mask_all);
    
    sigemptyset(&mask);
    sigaddset(&mask, SIGCHLD);

    signal(SIGCHLD, handler);
    
    initjobs(); /* Initialize the job list */
    while (n--)
    {
        sigprocmask(SIG_BLOCK, &mask, &prev_one);
        if ((pid = fork()) == 0)
        { /* Child */
            sigprocmask(SIG_SETMASK, &prev_one,NULL);
            execve("/bin/date", argv, NULL);
        }
        sigprocmask(SIG_BLOCK, &mask_all, &prev_all); /* Parent */
        addjob(pid);                                  /* Add the child to the job list */
        sigprocmask(SIG_SETMASK, &prev_one, NULL);
    }
    exit(0);
}


