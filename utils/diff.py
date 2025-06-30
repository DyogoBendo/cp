def compare_files(file1_path, file2_path):
    with open(file1_path, 'r', encoding='utf-8') as f1, open(file2_path, 'r', encoding='utf-8') as f2:
        lines1 = f1.readlines()
        lines2 = f2.readlines()

    max_lines = max(len(lines1), len(lines2))
    differences = []

    for i in range(max_lines):
        line1 = lines1[i].rstrip('\n') if i < len(lines1) else '[MISSING]'
        line2 = lines2[i].rstrip('\n') if i < len(lines2) else '[MISSING]'

        if line1 != line2:
            differences.append((i + 1, line1, line2))

    return differences

# Example usage
file1 = 'test_output.txt'
file2 = 'user_output.txt'

diffs = compare_files(file1, file2)

if diffs:
    print("Differences found:")
    for line_num, line1, line2 in diffs:
        print(f"Line {line_num}:\n  File1: {line1}\n  File2: {line2}")
else:
    print("The files are identical.")
