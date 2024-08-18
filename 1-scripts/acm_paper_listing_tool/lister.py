import re
import pandas as pd

# 파일 경로를 지정하세요
file_path = 'papers.txt'

# 데이터를 저장할 리스트 초기화
data = []

# 정규 표현식을 이용한 논문 정보 추출 패턴 (부분적으로 누락된 정보를 허용)
pattern = r'^(.*?)\.\s*\((\d{4})\)\.\s*(.*?)\.\s*(.*?)?\.\s*(https?://[^\s]+)?'

# 파일 읽기
with open(file_path, 'r', encoding='utf-8') as file:
    for line in file:
        match = re.match(pattern, line.strip())
        if match:
            # 각 그룹에 대해 추출, 누락된 정보는 빈 문자열로 처리
            authors = match.group(1) if match.group(1) else ''
            year = match.group(2) if match.group(2) else ''
            title = match.group(3) if match.group(3) else ''
            venue = match.group(4) if match.group(4) else ''
            link = match.group(5) if match.group(5) else ''
            # 데이터를 리스트에 추가
            data.append([title, authors, venue, year, link])

# 데이터를 DataFrame으로 변환
df = pd.DataFrame(data, columns=['논문명', '저자', 'Venue', '출판연도', '논문링크'])

# 엑셀 파일로 저장
output_file = 'papers_info.xlsx'
df.to_excel(output_file, index=False)

print(f"데이터가 '{output_file}' 파일에 저장되었습니다.")
