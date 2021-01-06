import shutil
import os

shader_folder_path = "../../MyOpenGL/Shaders"
build_folder_path = "Shaders"

files = os.listdir()
if "Shaders" not in files:
    destination = shutil.copytree(shader_folder_path, build_folder_path)
    print(f"Copy shaders folder to {destination}")
