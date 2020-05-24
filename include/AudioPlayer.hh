#ifndef AUDIOPLAYER_HH
#define AUDIOPLAYER_HH

#include <SFML/Audio.hpp>
#include "../include/Button.hh"

#define OFFSET 10

class AudioPlayer{
	private:
		std::string songs[5] = {"astronomia", "blinding_lights", "holding_out_for_a_hero", "level_of_concern", "never_gonna_give_you_up"};
		sf::Music *music;
		Button buttons[4];
		int active_song = 0;

		void highlight_buttons(bool on);
		std::string get_active_song_path();
	public:
		AudioPlayer(){}
		AudioPlayer(sf::Vector2i pos);
		~AudioPlayer();
		Button *get_buttons();
		void play();
		void stop();
		void prev();
		void next();
		void prev_forced();
		void next_forced();
};

#endif
