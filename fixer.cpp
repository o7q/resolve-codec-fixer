#include <iostream>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

int main()
{
    std::string extension = ".mp4";
    std::string directory = "<PATH>";

    for (const auto &entry : fs::recursive_directory_iterator(directory))
    {
        if (fs::is_regular_file(entry.path()) && entry.path().extension() == extension)
        {
            std::string inFile = entry.path().string();
            std::string outFile = entry.path().parent_path().string() + "/temp" + extension;

            std::string ffmpegScript = "ffmpeg -i \"" + inFile + "\" -c:v copy -c:a mp3 -b:a 320k \"" + outFile + "\"";
            std::cout << ffmpegScript << std::endl;

            std::system(ffmpegScript.c_str());

            if (fs::exists(outFile))
            {
                fs::remove(inFile);
                fs::rename(outFile, inFile);
            }

            std::cout << entry.path() << std::endl;
        }
    }
}