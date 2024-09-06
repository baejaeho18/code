import os
import pandas as pd
from selenium import webdriver
from selenium.webdriver.chrome.options import Options
import requests

# Brave 브라우저 경로 설정
brave_path = "/path/to/brave-browser"

# 엑셀 파일에서 웹사이트 목록 읽어오기
excel_file = "websites.xlsx"  # 웹사이트 목록이 있는 엑셀 파일
df = pd.read_excel(excel_file)

# 웹사이트 목록을 리스트로 변환
urls = df['URL'].tolist()  # 엑셀 파일에서 URL이 있는 열 이름을 'URL'로 가정

# 수집된 스크립트를 저장할 디렉토리 설정
script_dir = "collected_scripts"
os.makedirs(script_dir, exist_ok=True)

# 중복 확인을 위해 이미 저장된 스크립트의 파일명을 기록
collected_files = set(os.listdir(script_dir))

# Selenium WebDriver 설정 (Brave)
options = Options()
options.binary_location = brave_path
driver = webdriver.Chrome(options=options)

# DevTools Protocol 활성화
driver.execute_cdp_cmd("Network.enable", {})

# 네트워크 요청 이벤트 감지
def log_request(request):
    url = request["request"]["url"]
    if "block" in request["response"].get("statusText", "").lower():
        # URL에서 파일명 추출
        file_name = url.split("/")[-1]
        if file_name and file_name not in collected_files:
            try:
                # 스크립트 내용 다운로드
                response = requests.get(url)
                if response.status_code == 200:
                    file_path = os.path.join(script_dir, file_name)
                    with open(file_path, "w") as file:
                        file.write(response.text)
                    collected_files.add(file_name)
                    print(f"Saved blocked script: {file_name}")
            except Exception as e:
                print(f"Failed to download {url}: {e}")

# 각 웹사이트 방문 및 차단된 스크립트 수집
for url in urls:
    try:
        driver.get(url)
        driver.execute_cdp_cmd("Network.requestWillBeSent", log_request)
    except Exception as e:
        print(f"Failed to load {url}: {e}")

# 브라우저 종료
driver.quit()
