import shutil

example_src = "../../UnitTests/src/ExampleSrcFile.txt"
build_folder_path = "ExampleSrcFile.txt"

destination = shutil.copy(example_src, build_folder_path)
print(f"Copy example source file to {destination}")
