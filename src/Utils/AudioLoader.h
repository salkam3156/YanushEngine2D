#pragma once
#include "../stdafx.h"
#include <SFML/Audio.hpp>

class AudioLoader
{
	using MusicPtr = std::unique_ptr<sf::Music>;
public:
	void LoadMusic(std::string filename);
	void PlayMusic() const;

private:
	std::vector<MusicPtr> sounds_;
	MusicPtr music_;
};