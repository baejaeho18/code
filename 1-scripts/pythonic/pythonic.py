import os
import sys
import openai

def get_api_key(api_path):
    # Read API key from file
    with open(api_path, 'r', encoding='utf-8') as file:
        api_key = file.read().strip()
    return api_key

def ask_to_gpt(api_key, file_path):
    content = get_code_file(file_path)
    
    messages = []
    messages.append({"role":"user", "content":content})

    response = openai.ChatCompletion.create(
        model = "gpt-3.5-turbo",
        messages = messages
    ).choices[0].message.content

    return response

def get_code_file(file_path):   
    with open(file_path, 'r', encoding='utf-8') as file:
        content = file.read()
    return content

def save_code_only(response):
    response_path = 'response.txt'
    # 코드부분만 가져오는 처리
    
    with open(response_path, 'w', encoding='utf-8') as file:
        file.write(response)
    return response_path

def compare_results(origin_code_path, update_code_path):
    # 원본과 수정본의 결과 같은지 확인한 후,
    return True

def show_diff(origin_code_path, update_code_path):
    origin = get_code_file(origin_code_path)
    update = get_code_file(update_code_path)


    

file_path = sys.argv[1]
if len(sys.argv) != 2:
    print("Insufficient arguments")
    sys.exit()

api_path = 'gpt-api-key'
api_key = get_api_key(api_path)

chance = 3
while(chance > 0):
    response = ask_to_gpt(api_key, file_path)
    updated_code_path = save_code_only(response)

    if compare_results(file_path, updated_code_path):
        show_diff(file_path, updated_code_path)
        break
    else:
        chance -= 1