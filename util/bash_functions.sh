# Compile cpp file, run, test;
# Example:
# sanit program.cpp r t test_file
# base: just compile with sanitizer
# if r: run
# if t: test with test_file
sanit() {
      if [ -z "$1" ]; then
          echo "Usage: compile_with_sanitizer <cpp_file> [r] [t <test_file>]"
          echo "  <cpp_file>: The .cpp file to compile."
          echo "  r: Run the binary immediately after compilation."
          echo "  t <test_file>: Specify a test file to use as input when running the binary."
          return 1
      fi

      cpp_file="$1"
      output_name="${cpp_file%.cpp}"
      run_binary=false
      test_file=""

      shift
      while [[ $# -gt 0 ]]; do
          case "$1" in
              r)
                  run_binary=true
                  shift
                  ;;
              t)
                  if [ -z "$2" ]; then
                      echo "Error: Missing test file name after 't'."
                      return 1
                  fi
                  test_file="$2"
                  shift 2
                  ;;
              *)
                  echo "Error: Unknown option '$1'."
                  return 1
                  ;;
          esac
      done

      if [ ! -f "$cpp_file" ]; then
          echo "Error: File '$cpp_file' not found."
          return 1
      fi

      echo "Compiling $cpp_file with AddressSanitizer..."
      g++ -fsanitize=address,undefined -g -o "$output_name" "$cpp_file"

      if [ $? -eq 0 ]; then
          echo "Compilation successful. Output binary: ./$output_name"
      else
          echo "Compilation failed."
          return 1
      fi

      if [ "$run_binary" = true ]; then
          if [ -n "$test_file" ]; then
              if [ ! -f "$test_file" ]; then
                  echo "Error: Test file '$test_file' not found."
                  return 1
              fi
              echo "Running ./$output_name with input from $test_file..."
              ./"$output_name" < "$test_file"
          else
              echo "Running ./$output_name..."
              ./"$output_name"
          fi
      fi
}
