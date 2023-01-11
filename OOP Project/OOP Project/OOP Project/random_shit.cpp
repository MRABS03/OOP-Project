//#include<iostream>
//#include<Windows.h>
//#include<fileapi.h>
//#include<SetupAPI.h>
//using namespace std;
//
//int main() {
//	BOOL GetDiskFreeSpaceW(
//		 LPCWSTR lpRootPathName,
//		 LPDWORD lpSectorsPerCluster,
//		 LPDWORD lpBytesPerSector,
//		 LPDWORD lpNumberOfFreeClusters,
//		 LPDWORD lpTotalNumberOfClusters
//	);
//	//BOOL GetDiskFreeSpaceExA(
//	//	[in, optional]  LPCSTR          lpDirectoryName,
//	//	[out, optional] PULARGE_INTEGER lpFreeBytesAvailableToCaller,
//	//	[out, optional] PULARGE_INTEGER lpTotalNumberOfBytes,
//	//	[out, optional] PULARGE_INTEGER lpTotalNumberOfFreeBytes
//	//);
//	/*BOOL GetDiskFreeSpaceExW(
//		[in, optional]  LPCWSTR         lpDirectoryName,
//		[out, optional] PULARGE_INTEGER lpFreeBytesAvailableToCaller,
//		[out, optional] PULARGE_INTEGER lpTotalNumberOfBytes,
//		[out, optional] PULARGE_INTEGER lpTotalNumberOfFreeBytes
//	);*/
//	//BOOL GetDiskFreeSpaceW(
//	//	[in]  LPCWSTR lpRootPathName,
//	//	[out] LPDWORD lpSectorsPerCluster,
//	//	[out] LPDWORD lpBytesPerSector,
//	//	[out] LPDWORD lpNumberOfFreeClusters,
//	//	[out] LPDWORD lpTotalNumberOfClusters
//	//);
//
//	/*WINSETUPAPI BOOL SetupDiGetDeviceRegistryPropertyA(
//		[in]            HDEVINFO         DeviceInfoSet,
//		[in]            PSP_DEVINFO_DATA DeviceInfoData,
//		[in]            DWORD            Property,
//		[out, optional] PDWORD           PropertyRegDataType,
//		[out, optional] PBYTE            PropertyBuffer,
//		[in]            DWORD            PropertyBufferSize,
//		[out, optional] PDWORD           RequiredSize
//	);*/
//}

//#include<iostream>
//#include<Windows.h>
//using namespace std;
//
//int main()
//{
//	int a;
//
//	LPCWSTR drive[4] = { L"C:\\",L"D:\\",L"E:\\",L"D:\\User\\Desktop"};
//
//	cout << "Which Drive Properties do you want to access?" << endl;
//	cout << "1> Local Disk C" << endl;
//	cout << "2>New Volume D" << endl;
//	cout << "3>Drive E" << endl;
//	cout << "Answer: ";
//	cin >> a;
//
//	UINT test;
//
//	if (a == 1)
//	{
//		a = 0;
//		test = GetDriveType(drive[a]);
//	}
//
//	else if (a == 2)
//	{
//		a = 1;
//		test = GetDriveType(drive[a]);
//	}
//
//	else if (a == 3)
//	{
//		a = 2;
//		test = GetDriveType(drive[a]);
//	}
//	
//
//	switch (test)
//	{
//	case 0:
//	{
//		printf("Drive %S is type %d - Cannot be determined.\n", drive[a], test);
//		break;
//	}
//
//	case 1:
//	{
//		printf("Drive %S is type %d - Invalid root path/Not available.\n", drive[a], test);
//		break;
//	}
//	case 2:
//	{
//		printf("Drive %S is type %d - USB.\n", drive[a], test);
//		break;
//	}
//
//	case 3:
//	{
//		printf("Drive %S is type %d - Fixed.\n", drive[a], test);
//		break;
//	}
//
//	case 4:
//	{
//		printf("Drive %S is type %d - Network.\n", drive[a], test);
//		break;
//	}
//
//	case 5:
//	{
//		printf("Drive %S is type %d - CD-ROM.\n", drive[a], test);
//		break;
//	}
//
//	case 6:
//	{
//		printf("Drive %S is type %d - RAMDISK.\n", drive[a], test);
//		break;
//	}
//
//	default: "Unknown value!\n";
//
//	}
//}

//#include<iostream>
//#include"fmod.h"
//using namespace std;
//int main() {
//    FMOD::System* system;
//    FMOD::Sound* sound;
//    FMOD::Channel* channel;
//
//    // Initialize the FMOD system
//    FMOD_System_Create(&system);
//    FMOD_System_Init(system, 32, FMOD_INIT_NORMAL, NULL);
//
//    // Load the audio file
//    FMOD_System_CreateSound(system, "song.mp3", FMOD_DEFAULT, 0, &sound);
//
//    // Play the audio file
//    FMOD_System_PlaySound(system, sound, NULL, false, &channel);
//
//    // Wait for the song to finish
//    while (true) {
//        FMOD_BOOL isPlaying;
//        FMOD_Channel_IsPlaying(channel, &isPlaying);
//        if (!isPlaying) break;
//    }
//
//    // Clean up
//    FMOD_Sound_Release(sound);
//    FMOD_System_Close(system);
//    FMOD_System_Release(system);
//
//    return 0;
//}

//
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <fstream>
//
//class AudioPlayerV2
//{
//private:
//    std::string manufacturer;
//    std::string model_number;
//    std::string storage_media;  // CD or USB
//    std::vector<std::string> song_list;
//    std::string current_song;
//    bool is_playing;
//    bool is_powered_on;
//
//public:
//    AudioPlayerV2(std::string manufacturer, std::string model_number, std::string storage_media)
//        : manufacturer(manufacturer), model_number(model_number), storage_media(storage_media),
//        is_playing(false), is_powered_on(false)
//    {
//    }
//
//    // Mounts the storage media and starts playing the first song
//    void mount()
//    {
//        if (storage_media == "CD" || storage_media == "USB")
//        {
//            current_song = song_list[0];
//            is_playing = true;
//            display_current_song();
//        }
//        else
//        {
//            std::cout << "Error: unsupported storage media" << std::endl;
//        }
//    }
//
//    // Unmounts the storage media and resets the song tracking
//    void unmount()
//    {
//        storage_media = "";
//        current_song = "";
//        is_playing = false;
//    }
//
//    // Shuffles the playlist randomly
//    void shuffle_playlist()
//    {
//        std::random_shuffle(song_list.begin(), song_list.end());
//    }
//
//    // Saves the playlist to a file on disk
//    void save_playlist(std::string filename)
//    {
//        std::ofstream out_file(filename);
//        for (const std::string& song : song_list)
//        {
//            out_file << song << std::endl;
//        }
//        out_file.close();
//    }
//
//    // Loads a playlist from a file on disk
//    void load_playlist(std::string filename)
//    {
//        std::ifstream in_file(filename);
//        std::string song;
//        while (std::getline(in_file, song))
//        {
//            song_list.push_back(song);
//        }
//        in_file.close();
//    }
//
//    // Adds a new audio file to the playlist
//    void add_to_playlist(std::string song)
//    {
//        song_list.push_back(song);
//    }
//
//    // Deletes an audio file from the playlist
//    void delete_from_playlist(std::string song)
//    {
//        song_list.erase(std::remove(song_list.begin(), song_list.end(), song), song_list.end());
//    }
//
//    // Searches for an audio file in the playlist
//    bool search_in_playlist(std::string song)
//    {
//        return std::find(song_list.begin(), song_list.end(), song) != song_list.end();
//    }
//
//}


//
//
//#include <stdio.h>
//#include <time.h>
//#include <windows.h>
//#include <string>
//
//using namespace std;
//
//string allDrives;
//
//char getRemovableDisk();
//
//int main(void) {
//    char driveLetter = getRemovableDisk();
//    while (1) {
//        driveLetter = getRemovableDisk();
//        if (driveLetter != '0') {
//            printf("%c \n", driveLetter);
//        }
//
//        Sleep(1000);
//    }
//
//    return 0;
//}
//
//char getRemovableDisk() {
//    char drive = '0';
//
//    char szLogicalDrives[MAX_PATH];
//    DWORD dwResult = GetLogicalDriveStrings(MAX_PATH, szLogicalDrives);
//
//    string currentDrives = "";
//
//    //cout << dwResult << endl;
//    for (int i = 0; i < dwResult; i++) {
//        if (szLogicalDrives[i] > 64 && szLogicalDrives[i] < 90) {
//            currentDrives.append(1, szLogicalDrives[i]);
//            if (allDrives.find(szLogicalDrives[i]) > 100) {
//                drive = szLogicalDrives[i];
//            }
//
//        }
//    }
//
//    allDrives = currentDrives;
//
//    return drive;
//}
//
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <fstream>
//
//using namespace std;
//
//class AudioPlayerV2
//{
//private:
//    std::string manufacturer;
//    std::string model_number;
//    std::string storage_media;  // CD or USB
//    std::vector<std::string> song_list;
//    std::string current_song;
//    bool is_playing;
//    bool is_powered_on;
//
//public:
//    AudioPlayerV2(std::string manufacturer, std::string model_number, std::string storage_media)
//        : manufacturer(manufacturer), model_number(model_number), storage_media(storage_media),
//        is_playing(false), is_powered_on(false)
//    {
//    }
//
//    // Mounts the storage media and starts playing the first song
//    void mount()
//    {
//        if (storage_media == "CD" || storage_media == "USB")
//        {
//            current_song = song_list[0];
//            is_playing = true;
//            display_current_song();
//        }
//        else
//        {
//            std::cout << "Error: unsupported storage media" << std::endl;
//        }
//    }
//
//    // Unmounts the storage media and resets the song tracking
//    void unmount()
//    {
//        storage_media = "";
//        current_song = "";
//        is_playing = false;
//    }
//
//    // Shuffles the playlist randomly
//    void shuffle_playlist()
//    {
//        std::random_shuffle(song_list.begin(), song_list.end());
//    }
//
//    // Saves the playlist to a file on disk
//    void save_playlist(std::string filename)
//    {
//        std::ofstream out_file(filename);
//        for (const std::string& song : song_list)
//        {
//            out_file << song << std::endl;
//        }
//        out_file.close();
//    }
//
//    // Loads a playlist from a file on disk
//    void load_playlist(std::string filename)
//    {
//        std::ifstream in_file(filename);
//        std::string song;
//        while (std::getline(in_file, song))
//        {
//            song_list.push_back(song);
//        }
//        in_file.close();
//    }
//
//    // Adds a new audio file to the playlist
//    void add_to_playlist(std::string song)
//    {
//        song_list.push_back(song);
//    }
//
//    // Deletes an audio file from the playlist
//    void delete_from_playlist(std::string song)
//    {
//        song_list.erase(std::remove(song_list.begin(), song_list.end(), song), song_list.end());
//    }
//
//    // Searches for an audio file in the playlist
//    bool search_in_playlist(std::string song)
//    {
//        return std::find(song_list.begin(), song_list.end(), song) != song_list.end();
//    }
//

//#include <SFML/Audio.hpp>
//#include <iostream>
//
//int main()
//{
//    // Load the audio file
//    sf::Music music;
//    if (!music.openFromFile("audio.ogg"))
//    {
//        std::cout << "Failed to load audio file" << std::endl;
//        return 1;
//    }
//
//    // Start playback
//    music.play();
//
//    // Wait for the audio to finish playing
//    while (music.getStatus() == sf::Music::Playing)
//    {
//        sf::sleep(sf::milliseconds(100));
//    }
//
//    return 0;
//}

//#include <windows.h>
//#include <iostream>
//#include<playsoundapi.h>
//using namespace std;
//
//int main()
//{
//    // Play the audio file
//    if (!PlaySound(L"song1.wav", NULL, SND_FILENAME | SND_ASYNC))
//    {
//        std::cout << "Failed to play audio file" << std::endl;
//        return 1;
//    }
//
//    std::cout << "Playing audio file..." << std::endl;
//
//    // Wait for the audio to finish playing
//    while (PlaySound(NULL, NULL, 0))
//    {
//        Sleep(100);
//    }
//
//    return 0;
//}
//
//#include<iostream>
//#include<windows.h>
//
//using namespace std;
//
//int main() {
//	bool played=PlaySound(TEXT("Electronic-background-music-90-bpm.wav"), NULL, SND_SYNC);
//	cout << "Success or not: " << played << endl;
//
//	return 0;
//}

//
//#include<iostream>
//#include<windows.h>
//#include<mmsystem.h>
//
//
//using namespace std;
//int main() {
//
//
//	PlaySound(TEXT("Electronic-background-music-90-bpm.wav"), NULL, SND_SYNC);
//}

//#include<iostream>
//#include<list>
//using namespace std;
//
//int main() {
//	string s1;
//	list<string> l1;
//	for (int i = 0; i < 3; i++) {
//		cout << "\n" << "Enter the name of the song: " << endl;
//		cin >> s1;
//		l1.push_back(s1);
//	}
//	for (auto it = l1.begin(); it != l1.end(); ++it) {
//		cout << *it << endl;
//	}
//	}

//#include <Windows.h>
//#include <stdlib.h>
//#include <stdio.h>
//#include<iostream>
//using namespace std;
//
//int main()
//{
//
//	BOOLEAN bSuccess;
//
//	DWORD dwSectorsPerCluster;
//	DWORD dwBytesPerSector;
//	DWORD dwFreeClusters;
//	DWORD dwTotalClusters;
//
//	//get disk space for current drive
//	bSuccess = GetDiskFreeSpaceW(L"D:", &dwSectorsPerCluster, &dwBytesPerSector, &dwFreeClusters, &dwTotalClusters);
//
//	if (!bSuccess)
//	{
//		printf("Could not get drive information.\n");
//		exit(EXIT_FAILURE);
//	}
//
//	cout << "Bytes per sector:" << dwBytesPerSector << endl;
//	printf("Sectors per cluster: %d\n", dwSectorsPerCluster);
//	printf("Free clusters: %d\n", dwFreeClusters);
//	printf("Total clusters: %d\n", dwTotalClusters);
//
//	unsigned int uiKBPerCluster = (dwBytesPerSector * dwSectorsPerCluster) / 1024;
//	unsigned int a, b, freestorage, totalstorage;
//	a = (uiKBPerCluster * dwFreeClusters) / 1024;
//	freestorage = a - (0.024 * (uiKBPerCluster * dwFreeClusters) / 1024);
//	b = (uiKBPerCluster * dwTotalClusters) / 1024;
//	totalstorage = b - (0.024 * (uiKBPerCluster * dwTotalClusters) / 1024);
//
//
//	printf("You have %.2f MB of free storage\n", (double)freestorage);
//	printf("You have %.2f MB of total storage\n", (double)totalstorage);
//}

//#include <string>
//#include <iostream>
//#include <filesystem>
//namespace fs = std::filesystem;
//
//int main()
//{
//    std::string path = "/path/to/directory";
//    for (const auto& entry : fs::directory_iterator(path))
//        std::cout << entry.path() << std::endl;
//}

//#include <windows.h>
//#include <tchar.h>
//#include <stdio.h>
//
//void _tmain(int argc, TCHAR* argv[])
//{
//    WIN32_FIND_DATA FindFileData;
//    HANDLE hFind;
//
//    if (argc != 2)
//    {
//        _tprintf(TEXT("Usage: %s [target_file]\n"), argv[0]);
//        return;
//    }
//
//    _tprintf(TEXT("Target file is %s\n"), argv[1]);
//    hFind = FindFirstFile(argv[1], &FindFileData);
//    if (hFind == INVALID_HANDLE_VALUE)
//    {
//        printf("FindFirstFile failed (%d)\n", GetLastError());
//        return;
//    }
//    else
//    {
//        _tprintf(TEXT("The first file found is %s\n"),
//            FindFileData.cFileName);
//        FindClose(hFind);
//    }
//}
//
//#include <Windows.h>
//#include<vector>
//#include<string>
//#include<cstring>
//
//using namespace std;
//
//vector<string> get_all_files_names_within_folder(string folder)
//{
//    vector<string> names;
//    string search_path = folder + "/*.*";
//    WIN32_FIND_DATA fd;
//    HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd);
//    if (hFind != INVALID_HANDLE_VALUE) {
//        do {
//            // read all (real) files in current folder
//            // , delete '!' read other 2 default folder . and ..
//            if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
//                names.push_back(fd.);
//            }
//        } while (::FindNextFile(hFind, &fd));
//        ::FindClose(hFind);
//    }
//    return names;
//}