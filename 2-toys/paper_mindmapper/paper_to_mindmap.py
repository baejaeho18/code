import os
import re
import pypdf
import win32com.client

title = "WEBGRAPH: Capturing Advertising and Tracking Information Flows for Robust Blocking"
sections = ["Abstract", "1 Introduction", "2 Background & Related Work", "3 A DGRAPH Robustness", "4 W EBGRAPH", "5 W EBGRAPH Robustness", "6 Limitations", "7 Conclusion", "Acknowledgments", "References"]

def save_paragraphs_to_text(paragraph):
    with open("paragraphs.txt", "a", encoding="utf-8") as file:
        file.write(paragraph + "\n\n")

def extract_text_from_pdf(pdf_path):
    text = ""
    with open(pdf_path, "rb") as file:
        reader = pypdf.PdfReader(file)
        for page in reader.pages:
            text += page.extract_text()
    return text

def clean_text(text):
    # Remove newline characters that are not followed by a period
    lines = text.split('\n')
    cleaned_lines = [line.strip() if not line.endswith('.') else line for line in lines]
    cleaned_text = '\n'.join(cleaned_lines)
    return cleaned_text
    # return text

def add_topic(parent, title, position=None):
    try:
        topic = None
        if position is not None:
            topic = parent.AddSubTopic(title, position)
        else:
            topic = parent.AddSubTopic(title)
        topic.Text = title
        return topic
    except Exception as e:
        print(f"Error adding topic: {title}")
        print(e)

def process_text_to_mindmap(text):
    mindmanager = win32com.client.Dispatch("MindManager.Application")
    document = mindmanager.Documents.Add()
    root_topic = document.CentralTopic

    current_section_topic = None
    current_subsection_topic = None
    current_subsubsection_topic = None
    current_paragraph_topic = None
    current_section_index = -1

    paragraphs = text.split(".\n")
    paragraphs = [para for paragraph in paragraphs for para in paragraph.split(". ")]

    for paragraph in paragraphs:
        paragraph = paragraph.replace("\n", " ").replace("-\n", "").strip()
        save_paragraphs_to_text(paragraph)

        if title in paragraph:
            root_topic.Text = title

        if current_section_index + 1 < len(sections) and sections[current_section_index + 1] in paragraph:
            current_section_index += 1
            section_title = sections[current_section_index]
            section_position = paragraph.find(section_title) + len(section_title)
            current_section_topic = add_topic(root_topic, section_title)
            current_subsection_topic = None
            current_subsubsection_topic = None
            paragraph = paragraph[section_position:].strip()
            if paragraph:
                add_topic(current_section_topic, paragraph)
            continue

        subsection_match = re.match(r"^(\d+\.\d+)\s+(.+)$", paragraph)
        subsubsection_match = re.match(r"^(\d+\.\d+\.\d+)\s+(.+)$", paragraph)

        if subsection_match and current_section_topic:
            subsection_num, subsection_title = subsection_match.groups()
            subsection_position = paragraph.find(subsection_title) + len(subsection_title)
            current_subsection_topic = add_topic(current_section_topic, f"{subsection_num} {subsection_title}")
            current_subsubsection_topic = None
            paragraph = paragraph[subsection_position:].strip()
            if paragraph:
                add_topic(current_subsection_topic, paragraph)
            continue
        elif subsubsection_match and current_subsection_topic:
            subsubsection_num, subsubsection_title = subsubsection_match.groups()
            subsubsection_position = paragraph.find(subsubsection_title) + len(subsubsection_title)
            current_subsubsection_topic = add_topic(current_subsection_topic, f"{subsubsection_num} {subsubsection_title}")
            paragraph = paragraph[subsubsection_position:].strip()
            if paragraph:
                add_topic(current_subsubsection_topic, paragraph)
            continue

        if current_subsubsection_topic:
            current_paragraph_topic = add_topic(current_subsubsection_topic, paragraph.split(". ")[0])
        elif current_subsection_topic:
            current_paragraph_topic = add_topic(current_subsection_topic, paragraph.split(". ")[0])
        elif current_section_topic:
            if current_section_topic.Text.lower().startswith("references"):
                references = paragraph.split("[")
                for ref in references:
                    ref = ref.strip()
                    if ref:
                        add_topic(current_section_topic, ref)
                continue
            current_paragraph_topic = add_topic(current_section_topic, paragraph.split(". ")[0])
        else:
            current_paragraph_topic = add_topic(root_topic, paragraph.split(". ")[0])

        current_paragraph_sentences = paragraph.split(". ")[1:]
        for sentence in current_paragraph_sentences:
            add_topic(current_paragraph_topic, sentence)
    
    file_name = os.path.splitext(pdf_name)[0] + ".mmap"
    file_path = os.path.join(os.getcwd(), file_name)
    document.SaveAs(file_path)
    document.Close()

if __name__ == "__main__":
    pdf_name = input("PDF 파일 이름을 입력하세요 (확장자 포함): ")
    current_directory = os.getcwd()
    pdf_path = os.path.join(current_directory, pdf_name)
    
    if os.path.isfile(pdf_path):
        text = extract_text_from_pdf(pdf_path)
        cleaned_text = clean_text(text)
        process_text_to_mindmap(cleaned_text)
        print(f"{pdf_name} 파일이 성공적으로 MindManager 파일로 저장되었습니다.")
    else:
        print(f"{pdf_name} 파일을 현재 디렉토리에서 찾을 수 없습니다.")
