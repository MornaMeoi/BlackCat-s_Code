#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>
#include <sstream>
#include <cstring>

using namespace std;

vector<int> parse_image(stringstream& stream)
{
    int type = -1, width = 0, height = 0, dx = 0, dy = 0;
    string line;
    getline(stream, line, ')');

    const char *const delimeters = " =";
    char *token = strtok(line.data(), delimeters);
    while(token != nullptr)
    {
        int num = 0;
        if(strcmp(token, "layout"))
            num = atoi(strtok(nullptr, delimeters));
        if(strcmp(token, "dx") == 0)
            dx = num;
        else if(strcmp(token, "dy") == 0)
            dy = num;
        else if(strcmp(token, "width") == 0)
            width = num;
        else if(strcmp(token, "height") == 0)
            height = num;
        else
        {
            char *param = strtok(nullptr, delimeters);
            if(strcmp(param, "embedded") == 0)
                type = 0;
            else if(strcmp(param, "surrounded") == 0)
                type = 1;
            else
                type = 2;
        }
        token = strtok(nullptr, delimeters);
    }
    return {type, width, height, dx, dy};
}

int dx_used_by_images(const vector<vector<int>>& used_by_images, int current_dx, int current_dy)
{
    for(const auto& image : used_by_images)
        if(current_dx >= image[0] && current_dx <= image[0] + image[2] &&
           current_dy >= image[1] && current_dy <= image[1] + image[3])
            return image[0] + image[2];
    return 0;
}

bool is_empty_line(const string& line)
{
    for(char symb : line)
        if(!(symb == ' ' || symb == '\n'))
            return false;
    return true;
}

int main()
{
    ifstream inp("input.txt");
    int w, h, c;
    inp >> w >> h >> c;
    inp.ignore(1);

    int current_str_height = h, current_dx = 0, current_dy = 0;
    string current_word, line;
    vector<pair<int, int>> cords;
    vector<vector<int>> used_by_images;
    while(inp.peek() != EOF)
    {
        getline(inp, line);
        if(is_empty_line(line))
        {
            current_dy += h;
            continue;
        }
        stringstream l(line);
        while(l.peek() != '\n' && l.peek() != EOF)
        {
            l >> current_word;
            if(current_word == "(image")
            {
                vector<int> current_image = parse_image(l);
                if(current_image[0] == 0)
                {
                    int shift1, shift2;
                    do
                    {
                        shift1 = dx_used_by_images(used_by_images, current_dx, current_dy);
                        shift2 = dx_used_by_images(used_by_images, current_dx + current_image[1], current_dy);
                        if(shift1 != 0 || shift2 != 0)
                            current_dx = max(shift1, shift2);
                        if(current_dx + current_image[1] > w)
                        {
                            current_dx = 0;
                            current_dy += current_str_height;
                            current_str_height = h;
                        }
                        else
                            break;
                    }
                    while(shift1 != 0 || shift2 != 0);
                    cords.push_back({current_dx, current_dy});
                    current_str_height = max(current_str_height, current_image[2]);
                    current_dx += current_image[1] + c;
                }
                else if(current_image[0] == 1)
                {
                    if(current_dx != 0)
                        current_dx -= c;
                    int shift1, shift2;
                    do
                    {
                        shift1 = dx_used_by_images(used_by_images, current_dx, current_dy);
                        shift2 = dx_used_by_images(used_by_images, current_dx + current_image[1], current_dy);
                        if(shift1 != 0 || shift2 != 0)
                            current_dx = max(shift1, shift2);
                        if(current_dx + current_image[1] > w)
                        {
                            current_dx = 0;
                            current_dy += current_str_height;
                            current_str_height = h;
                        }
                        else
                            break;
                    }
                    while(shift1 != 0 || shift2 != 0);
                    cords.push_back({current_dx, current_dy});
                    used_by_images.push_back({current_dx, current_dy, current_image[1], current_image[2]});
                    current_dx += current_image[1];
                }
                else
                {
                    bool space = false;
                    if(current_dx != 0 && dx_used_by_images(used_by_images, current_dx-1, current_dy) != current_dx)
                    {
                        current_dx -= c;
                        space = true;
                    }
                    if(current_dx + current_image[3] >= 0 && current_dx + current_image[3] + current_image[1] <= w)
                        cords.push_back({current_dx + current_image[3], current_dy + current_image[4]});
                    else if(current_dx + current_image[3] < 0)
                        cords.push_back({0, current_dy + current_image[4]});
                    else if(current_dx + current_image[3] > w)
                        cords.push_back({w-current_image[1], current_dy + current_image[4]});
                    if(space)
                        current_dx += c;
                }
            }
            else
            {
                int shift1, shift2;
                do
                {
                    shift1 = dx_used_by_images(used_by_images, current_dx, current_dy);
                    shift2 = dx_used_by_images(used_by_images, current_dx + current_word.size() * c, current_dy);
                    if(shift1 != 0 || shift2 != 0)
                        current_dx = max(shift1, shift2);
                    if(current_dx + current_word.size() * c > w)
                    {
                        current_dx = 0;
                        current_dy += current_str_height;
                        current_str_height = h;
                    }
                    else
                        break;
                }
                while(shift1 != 0 || shift2 != 0);
                current_dx += current_word.size() * c + c;
            }
            l.ignore(1);
        }
    }
    for(const auto& cord : cords)
        cout << cord.first << ' ' << cord.second << endl;
    inp.close();
    return 0;
}