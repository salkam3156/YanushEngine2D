#pragma once
#include <SFML/Audio.hpp>

#include "../stdafx.h"

class AudioLoader
{
	using MusicPtr = std::unique_ptr<sf::Music>;
public:
	void LoadMusic(std::string filename);
	void PlayMusic() const;
	void SetMusicOriginLocation(sf::Vector2f location);

private:
	std::vector<MusicPtr> sounds_;
	MusicPtr music_;
};