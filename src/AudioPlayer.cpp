#include "../include/AudioPlayer.hh"

AudioPlayer::AudioPlayer(sf::Vector2i pos){
	this->buttons[0] = Button("play_btn", pos);
	this->buttons[1] = Button("stop_btn", sf::Vector2i(pos.x+OFFSET*1*2, pos.y));
	this->buttons[2] = Button("prev_btn", sf::Vector2i(pos.x+OFFSET*2*2, pos.y));
	this->buttons[3] = Button("next_btn", sf::Vector2i(pos.x+OFFSET*3*2, pos.y));
	this->music = new sf::Music();
	music->setVolume(65.f);
	music->setLoop(true);
	std::cout<<"Audio player created"<<std::endl;
}

AudioPlayer::~AudioPlayer(){
	delete music;
}

Button *AudioPlayer::get_buttons(){
	return buttons;
}

void AudioPlayer::play(){
	highlight_buttons(true);
	if(!music->openFromFile(get_active_song_path())){
		std::cout<<"Error while opening the song!"<<std::endl;
	}
	music->play();
}

void AudioPlayer::stop(){
	highlight_buttons(false);
	music->stop();
}

void AudioPlayer::prev(){
	active_song--;
	if(active_song<0)
		active_song = 4;
}

void AudioPlayer::next(){
	active_song++;
	if(active_song>4)
		active_song = 0;
}

void AudioPlayer::prev_forced(){
	music->stop();
	prev();
}

void AudioPlayer::next_forced(){
	music->stop();
	next();
}

/* PRIVATE METHODS */
void AudioPlayer::highlight_buttons(bool on){
	ButtonState state;
	if(on)
		state = ButtonState::active;
	else
		state = ButtonState::inactive;

	for(int i=0; i<4; i++){
		buttons[i].set_state(state);
	}
}

std::string AudioPlayer::get_active_song_path(){
	return "res/songs/"+songs[active_song]+".ogg";
}
