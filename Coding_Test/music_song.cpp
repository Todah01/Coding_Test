#if 0
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

string convert_sharp(string sheet) {
    unordered_map<string, string> sharp_code_list = { {"C#","1 "},{"D#","2 "},{"F#","3 "},{"G#","4 "},{"A#","5 "} };

    for (auto sharp_code : sharp_code_list) {
        while (sheet.find(sharp_code.first) != string::npos) {
            sheet.replace(sheet.find(sharp_code.first), sharp_code.first.length(), sharp_code.second);
        }
    }
    sheet.erase(remove(sheet.begin(), sheet.end(), ' '), sheet.end());
    return sheet;
}

vector<string> split_music_info(string info) {
    istringstream ss(info);
    string stringBuffer;
    vector<string> info_data;
    info_data.clear();
    while (getline(ss, stringBuffer, ',')) {
        info_data.push_back(stringBuffer);
    }
    return info_data;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    string music = convert_sharp(m);
    unordered_map<string, unordered_map<string, int>> music_map;

    for (int idx = 0; idx < musicinfos.size(); idx++) {
        vector<string> music_info_data = split_music_info(musicinfos[idx]);
        string sheet_music = convert_sharp(music_info_data[3]);

        int first_time = stoi(music_info_data[0].substr(0, 2)) * 60 + stoi(music_info_data[0].substr(3, 2));
        int second_time = stoi(music_info_data[1].substr(0, 2)) * 60 + stoi(music_info_data[1].substr(3, 2));
        int total_play_time = second_time - first_time;

        string total_code = "";
        for (int i = 0; i < total_play_time / sheet_music.length(); i++) {
            total_code += sheet_music;
        }
        total_code += sheet_music.substr(0, total_play_time % sheet_music.length());

        if (total_code.find(music) != string::npos) {
            music_map.insert({ music_info_data[2], {{"order", idx}, {"play_time", total_play_time}} });
        }
    }

    vector<pair<string, unordered_map<string, int>>> music_vec(music_map.begin(), music_map.end());
    sort(music_vec.begin(), music_vec.end(),
        [](const pair<string, unordered_map<string, int>>& a,
            const pair<string, unordered_map<string, int>>& b) {
                int play_time_A = a.second.at("play_time");
                int play_time_B = b.second.at("play_time");
                return play_time_A > play_time_B;
        });

    if (music_map.empty()) return "(None)";
    else return music_vec[0].first;
}
#endif