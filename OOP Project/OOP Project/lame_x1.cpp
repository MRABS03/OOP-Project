#include<iostream>
#include<string>
#include<Windows.h>
#include<fstream>
using namespace std;

class Audio_Player {
protected:
	string song_name,manufacturer_name;
	int minutes, seconds,model_number;
	bool mount;
public:
	Audio_Player() {
		song_name = "";
		manufacturer_name = "";
		minutes = 0;
		seconds = 0;
		model_number = 0;
		mount = false;
	}
	Audio_Player(string sn, string mn, int min, int sec, int model,bool status) {
		song_name = sn;
		manufacturer_name = mn;
		minutes = min;
		seconds = sec;
		model_number = model;
		mount = status;
	}

	virtual void set_songname(string sn) { song_name = sn; } 
	virtual void set_manufacturername(string mn) { manufacturer_name = mn; }
	virtual void set_minutes(int min) { minutes = min; }
	virtual void set_seconds(int sec) { seconds = sec; }
	virtual void set_modelnumber(int model) { model_number =model ; }
	virtual void set_mountstatus(bool status) { mount = status; }
	virtual void playsong() {
		bool played = PlaySound(TEXT("Electronic-background-music-90-bpm.wav"), NULL, SND_SYNC);
	}

	virtual string get_songname() { return song_name ; }
	virtual string get_manufacturername() { return manufacturer_name ; }
	virtual int get_minutes() { return minutes ; }
	virtual int get_seconds() { return seconds ; }
	virtual int get_modelnumber() { return model_number ; }
	virtual bool get_mountstatus() { return mount; }

};

class CD : public Audio_Player {
private:
	int CD_capacity;
public:
	CD() {
		song_name = "";
		manufacturer_name = "";
		minutes = 0;
		seconds = 0;
		model_number = 0;
		CD_capacity = 0;
		mount = false;
	}
	CD(string sn, string mn, int min, int sec, int model, bool status,int CD_cap) {
		song_name = sn;
		manufacturer_name = mn;
		minutes = min;
		seconds = sec;
		model_number = model;
		mount = status;
		CD_capacity = CD_cap;
	}
	 void set_songname(string sn) { song_name = sn; }
	 void set_manufacturername(string mn) { manufacturer_name = mn; }
	 void set_minutes(int min) { minutes = min; }
	 void set_seconds(int sec) { seconds = sec; }
	 void set_modelnumber(int model) { model_number = model; }
	 void set_mountstatus(bool status) { mount = status; }
	 void set_CDcapacity(int CD_cap) { CD_capacity = CD_cap; }
	 virtual void playsong() {
		 bool played = PlaySound(TEXT("Electronic-background-music-90-bpm.wav"), NULL, SND_SYNC);
	 }
	 string get_songname() { return song_name; }
	 string get_manufacturername() { return manufacturer_name; }
	 int get_minutes() { return minutes; }
	 int get_seconds() { return seconds; }
	 int get_modelnumber() { return model_number; }
	 bool get_mountstatus() { return mount; }
	 int get_CDcapacity() { return CD_capacity ; }
};

class USB :public Audio_Player {
private:
	int USB_capacity;
public:
	USB() {
		song_name = "";
		manufacturer_name = "";
		minutes = 0;
		seconds = 0;
		model_number = 0;
		USB_capacity = 0;
		mount = false;
	}
	USB(string sn, string mn, int min, int sec, int model, bool status, int CD_cap) {
		song_name = sn;
		manufacturer_name = mn;
		minutes = min;
		seconds = sec;
		model_number = model;
		mount = status;
		USB_capacity = CD_cap;
	}
	void set_songname(string sn) { song_name = sn; }
	void set_manufacturername(string mn) { manufacturer_name = mn; }
	void set_minutes(int min) { minutes = min; }
	void set_seconds(int sec) { seconds = sec; }
	void set_modelnumber(int model) { model_number = model; }
	void set_mountstatus(bool status) { mount = status; }
	void set_USBcapacity(int USB_cap) {
		if (USB_cap > 16) {
			cout << "\n" << "Limit exceeded! Insert USB limiting to 16 GBs" << endl;
		}
		else {
			USB_capacity = USB_cap;
		}
	}
	virtual void playsong() {
		bool played = PlaySound(TEXT("Electronic-background-music-90-bpm.wav"), NULL, SND_SYNC);
	}

	string get_songname() { return song_name; }
	string get_manufacturername() { return manufacturer_name; }
	int get_minutes() { return minutes; }
	int get_seconds() { return seconds; }
	int get_modelnumber() { return model_number; }
	bool get_mountstatus() { return mount; }
	int get_USBcapacity() { return USB_capacity; }
};

class Audio_Player2:public Audio_Player {
protected:
public:
	Audio_Player2() {
		song_name = "";
		manufacturer_name = "";
		minutes = 0;
		seconds = 0;
		model_number = 0;
		mount = false;
	}
	Audio_Player2(string sn, string mn, int min, int sec, int model, bool status) {
		song_name = sn;
		manufacturer_name = mn;
		minutes = min;
		seconds = sec;
		model_number = model;
		mount = status;
	}

	 void set_songname(string sn) { song_name = sn; }
	 void set_manufacturername(string mn) { manufacturer_name = mn; }
	 void set_minutes(int min) { minutes = min; }
	 void set_seconds(int sec) { seconds = sec; }
	 void set_modelnumber(int model) { model_number = model; }
	 void set_mountstatus(bool status) { mount = status; }
	 void addtoplaylist() {
		 string songnamee;
		 cout << "\n" << "Enter the song you want to insert in this playlist!! " << endl;
		 getline(cin, songnamee);
		 ofstream out;
		 out.open("songs1.txt", ios::app);
		 out << "\n" << songnamee;
	 }
	 void print_playlist() {
		 string x;
		 ifstream myfile;
		 myfile.open("songs1.txt", ios::in);
		 if (!myfile) { cout << "\n" << "Invalid prompt!!"; }
		 else {
			 while (1) {
				 getline(myfile, x);
				 if (myfile.eof())
					 break;
				 cout << x;
			 }
		 }
		 
	 }
	 virtual void playsong() {
		 bool played = PlaySound(TEXT("Electronic-background-music-90-bpm.wav"), NULL, SND_SYNC);
	 }


	 string get_songname() { return song_name; }
	 string get_manufacturername() { return manufacturer_name; }
	 int get_minutes() { return minutes; }
	 int get_seconds() { return seconds; }
	 int get_modelnumber() { return model_number; }
	 bool get_mountstatus() { return mount; }
};

int main(){
	Audio_Player2 a1;
	a1.addtoplaylist();
	a1.print_playlist();
	a1.playsong();

	return 0;
}
