import pandas as pd
import random

# CSV 파일에서 데이터 읽어오기
csv_file_path = 'result.csv'
df = pd.read_csv(csv_file_path)

# 학생 명단 (학번 없이)
std_names = [
    "강민우", "강예원", "곽철호", "구현우", "김성수", "김성지", "김승환", "김예은",
    "김예찬", "김지성", "김하람", "류정현", "박민찬", "박상훈", "박석준", "박세영",
    "박소연", "박승종", "박원진", "박정훈", "박지훈", "박하윤", "서은주", "심재인",
    "안수민", "안영준", "안준용", "오성진", "우지윤", "이유현", "이의진", "이준형",
    "이향우", "이호연", "장바다", "장유진", "장재근", "장현우", "전소명", "전혜선",
    "정희찬", "조성민", "조예린", "천국인", "천주현", "최동빈", "최복원", "최서현",
    "황수현"
]

# 설문 조사 결과를 리스트로 변환
survey_results = []
for _, row in df.iterrows():
    name = row['이름']
    preferences = row['희망팀원이름']
    survey_results.append({"name": name, "preferences": preferences})

print(survey_results)

# 유효한 이름 확인 함수
def is_valid_name(name):
    return name in std_names

# 유효한 희망 팀원만 반환하는 함수
def get_valid_preferences(preferences):
    return [name for name in preferences if is_valid_name(name)]

# 팀 매칭 함수
def match_teams(survey_results, std_names):
    teams = []
    used_students = set()
    
    for student in survey_results:
        name = student["name"]
        if name in used_students:
            continue
        preferences = get_valid_preferences(student["preferences"])
        team = [name]
        used_students.add(name)
        
        for pref in preferences:
            if pref not in used_students and len(team) < 4:
                team.append(pref)
                used_students.add(pref)
        
        if len(team) >= 3:
            teams.append(team)
        else:
            for member in team:
                used_students.remove(member)
    
    remaining_students = [s["name"] for s in survey_results if s["name"] not in used_students]
    random.shuffle(remaining_students)
    
    while remaining_students:
        team_size = min(4, len(remaining_students))
        team = remaining_students[:team_size]
        remaining_students = remaining_students[team_size:]
        teams.append(team)
    
    return teams

# 팀 매칭 결과 출력
def print_teams(teams):
    for i, team in enumerate(teams, 1):
        print(f"Team {i}: {', '.join(team)}")

# 매칭을 수행하고 결과를 출력
teams = match_teams(survey_results, std_names)
print_teams(teams)
