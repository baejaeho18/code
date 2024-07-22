import re
import pandas as pd

# Step 1: Load rules from easylist.txt
def load_easylist_rules(file_path):
    rules = []
    with open(file_path, 'r', encoding='utf-8') as f:
        for line in f:
            line = line.strip()
            if line and not line.startswith('!'):
                rules.append(line)
    return rules

# Step 2: Read website list from Alexa_dataset.csv
def read_website_list(file_path):
    df = pd.read_csv(file_path, names=['rank', 'website'])
    return df['website'].tolist()

# Step 3: Label websites based on rules
def label_websites(websites, rules):
    pattern = '|'.join(rules)
    labels = []
    for website in websites:
        if re.search(pattern, website):
            labels.append(1)
        else:
            labels.append(0)
    return labels

# Main function to execute the process
def main():
    # File paths
    easylist_file = 'easylist.txt'
    alexa_file = 'top-1m.csv'
    
    # Step 1: Load rules
    rules = load_easylist_rules(easylist_file)
    
    # Step 2: Read website list
    websites = read_website_list(alexa_file)
    
    # Step 3: Label websites
    labels = label_websites(websites, rules)
    
    # Convert to DataFrame for easy manipulation
    df = pd.DataFrame({'website': websites, 'label': labels})
    
    # Step 4: Count and print number of harmful websites
    num_harmful_sites = df['label'].sum()
    print(f"Number of harmful sites: {num_harmful_sites}")
    
    # Save labeled data to CSV (optional)
    labeled_file = 'labeled_websites.csv'
    df.to_csv(labeled_file, index=False)

if __name__ == "__main__":
    main()
