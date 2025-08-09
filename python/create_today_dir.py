#!/usr/bin/env python3

# create_today_dir.py
import os
from datetime import datetime

def get_today_folder(base_path="."):
    today = datetime.today().strftime('%Y-%m-%d')
    today_path = os.path.join(base_path, today)
    os.makedirs(today_path, exist_ok=True)
    return today_path

# 단독 실행 시 경로 출력
if __name__ == "__main__":
    path = get_today_folder()
    print(f"[✓] 오늘 날짜 폴더 생성됨: {path}")
