import os
import pypdf
import win32com.client

title = "ADGRAPH: A Graph-Based Approach to Ad and Tracker Blocking"
sections = ["Abstract —", "I. I NTRODUCTION", "II. B ACKGROUND AND RELATED WORK", "III. A DGRAPH DESIGN", "IV. A DGRAPH EVALUATION", "V. D ISCUSSIONS", "VI. C ONCLUSION", "ACKNOWLEDGMENT", "REFERENCES"]
subsections = ["A. Problem Difficulty", "B. Existing Blocking Techniques", "C. JavaScript Attribution",
              "A. Graph Representation", "B. Graph Construction", "C. Feature Extraction", "D. Classification", 
              "A. Accuracy", "B. Disagreements Between ADGRAPH and Filter Lists", "C. Site Breakage", "D. Feature Analysis", "E. Tradeoffs in Browser Instrumentation", "F. Performance", 
              "A. Offline Application of ADGRAPH", "B. ADGRAPH Limitations And Future Improvements"
              ]
subsubsections = ["Domain Based Blocking.", "JavaScript Code Unit Classification.", "Evaluation Issues.", 
                "JavaScript Stack Walking.", "AdTracker.", "JSGraph.", 
                "Nodes.", "Edges.", "Composition Examples.",
                "Blink Instrumentation.", "V8 Instrumentation", "JavaScript Attribution Example.", 
                "Structural Features.", "Content Features.", 
                "Ground Truth.", "Results.", 
                "Methodology.", "False Positive Analysis.", "False Negative Analysis.", 
                "Methodology.", "Results.", 
                "Structural Features.", "Content Features.", "Ablation Analysis.", 
                "Ground Truth.", "Features.", "Classification Granularity."
                ]

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

    for paragraph in text.split(".\n"):
        paragraph = paragraph.replace("\n", " ").replace("-\n", "")
        save_paragraphs_to_text(paragraph)

        if title in paragraph:
            root_topic.Text = title

        # Process sections
        for section in sections:
            if section in paragraph:
                current_section_topic = add_topic(root_topic, section)
                current_subsection_topic = None
                current_subsubsection_topic = None
                paragraph = paragraph.replace(section, "")
                break

        # Process subsections
        for subsect in subsections:
            if subsect in paragraph and current_section_topic:
                current_subsection_topic = add_topic(current_section_topic, subsect)
                current_subsubsection_topic = None
                paragraph = paragraph.replace(subsect, "")
                break

        # Process subsubsections
        for subsubsect in subsubsections:
            if subsubsect in paragraph and current_subsection_topic:
                current_subsubsection_topic = add_topic(current_subsection_topic, subsubsect)
                paragraph = paragraph.replace(subsubsect, "")
                break

        # Process paragraph
        if current_subsubsection_topic:
            current_paragprah_topic = add_topic(current_subsubsection_topic, paragraph.split(". ")[0])
        elif current_subsection_topic:
            current_paragprah_topic = add_topic(current_subsection_topic, paragraph.split(". ")[0])
        elif current_section_topic:
            if current_section_topic.Text == "REFERENCE":
                add_topic(current_section_topic, paragraph.split("["))
                continue
            current_paragprah_topic = add_topic(current_section_topic, paragraph.split(". ")[0])
        else:
            current_paragprah_topic = add_topic(root_topic, paragraph.split(". ")[0])

        current_pragraph_sentences = paragraph.split(". ")[1:]
        for sentence in current_pragraph_sentences:
            add_topic(current_paragprah_topic, sentence)
    
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
