import pandas as pd
from adblockparser import AdblockRules

# Step 1: Load rules from easylist.txt
def load_easylist_rules(file_path, invalid_rules_path):
    with open(file_path, 'r', encoding='utf-8') as file:
        rules = [line.strip() for line in file if not line.startswith('!') and line.strip()]
    
    # Save invalid rules to a file (if needed)
    # This example assumes all loaded rules are valid, adjust if necessary
    return rules

# Step 2: Read website list from Alexa_dataset.csv
def read_website_list(file_path):
    df = pd.read_csv(file_path, names=['rank', 'website'])
    return df['website'].tolist()

# Step 3: Label websites based on rules using adblockparser
def label_websites(websites, rules):
    adblock_rules = AdblockRules(rules)
    labels = [1 if adblock_rules.should_block(url) else 0 for url in websites]
    return labels

# Main function to execute the process
def main():
    # File paths
    easylist_file = 'easylist.txt'
    alexa_file = 'top-1m.csv'   # https://www.kaggle.com/datasets/cheedcheed/top1m
    invalid_rules_path = 'invalid_rules.txt'
    labeled_file = 'labeled_websites.csv'
    
    # Step 1: Load rules
    rules = load_easylist_rules(easylist_file, invalid_rules_path)
    
    # Step 2: Read website list
    websites = read_website_list(alexa_file)
    
    # Step 3: Label websites
    labels = label_websites(websites, rules)
    
    # Convert to DataFrame for easy manipulation
    df = pd.DataFrame({'website': websites, 'label': labels})
    
    # Step 4: Count and print number of harmful websites
    num_harmful_sites = df['label'].sum()
    print(f"Number of harmful sites: {num_harmful_sites}")
    
    # Save labeled data to CSV
    df.to_csv(labeled_file, index=False)

if __name__ == "__main__":
    main()
