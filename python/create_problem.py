#!/usr/bin/env python3

import os
import sys

def create_problem_files(problem_id):
    base_dir = os.getcwd()
    problem_dir = os.path.join(base_dir, problem_id)
    os.makedirs(problem_dir, exist_ok=True)

    py_file = os.path.join(problem_dir, f"{problem_id}.py")
    test_file = os.path.join(problem_dir, f"{problem_id}_test.py")

    with open(py_file, "w", encoding="utf-8") as f:
        f.write(f"# BOJ {problem_id}\n\n")

    with open(test_file, "w", encoding="utf-8") as f:
        f.write(f"# Tests for BOJ {problem_id}\n")
        f.write("def test_solution():\n    pass\n")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("사용법: create_problem.py [문제번호]")
        sys.exit(1)

    problem_id = sys.argv[1]
    create_problem_files(problem_id)
