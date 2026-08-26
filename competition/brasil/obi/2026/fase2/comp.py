import subprocess
import time
from pathlib import Path

# Configuration
EXECUTABLE = "./a.out"
BASE_DIR = "2026f2pj_loja"
TIME_LIMIT = 5.0  # seconds

# Terminal colors for better readability
class Colors:
    AC = '\033[92m'  # Green
    WA = '\033[91m'  # Red
    TLE = '\033[93m' # Yellow
    RE = '\033[95m'  # Magenta
    RESET = '\033[0m'

def test_program():
    base_path = Path(BASE_DIR)
    
    if not Path(EXECUTABLE).exists():
        print(f"Error: Executable '{EXECUTABLE}' not found. Did you compile your C++ code?")
        return
    if not base_path.exists():
        print(f"Error: Directory '{BASE_DIR}' not found.")
        return

    # Sort folders numerically
    folders = [f for f in base_path.iterdir() if f.is_dir() and f.name.isdigit()]
    folders.sort(key=lambda x: int(x.name))

    total_tests = 0
    passed_tests = 0

    print(f"Running tests on {EXECUTABLE} (Time Limit: {TIME_LIMIT}s)\n" + "-"*50)
    
    for folder in folders:
        # Sort files numerically
        in_files = [f for f in folder.glob("*.in") if f.stem.isdigit()]
        in_files.sort(key=lambda x: int(x.stem))

        for in_file in in_files:            
            sol_file = in_file.with_suffix('.sol')
            if not sol_file.exists():
                continue
            
            total_tests += 1
            test_name = f"{folder.name}/{in_file.name}"
            
            # Read input and expected output
            with open(in_file, 'r', encoding='utf-8') as f:
                input_data = f.read()
            with open(sol_file, 'r', encoding='utf-8') as f:
                expected_output = f.read().strip()

            # Run the program
            start_time = time.perf_counter()
            try:
                process = subprocess.run(
                    [EXECUTABLE],
                    input=input_data,
                    text=True,
                    capture_output=True,
                    timeout=TIME_LIMIT
                )
                elapsed_time = time.perf_counter() - start_time
                actual_output = process.stdout.strip()                

                if process.returncode != 0:
                    status = f"{Colors.RE}Runtime Error (RE){Colors.RESET}"
                elif actual_output == expected_output:
                    status = f"{Colors.AC}Accepted (AC){Colors.RESET}"
                    passed_tests += 1
                else:
                    status = f"{Colors.WA}Wrong Answer (WA){Colors.RESET}"
                    
            except subprocess.TimeoutExpired:
                elapsed_time = TIME_LIMIT
                status = f"{Colors.TLE}Time Limit Exceeded (TLE){Colors.RESET}"

            # Print result for this test case
            print(f"Test [{test_name:^8}] | Time: {elapsed_time:.3f}s | Status: {status}")

    print("-" * 50)
    print(f"Results: {passed_tests}/{total_tests} test cases passed.")

if __name__ == "__main__":
    test_program()