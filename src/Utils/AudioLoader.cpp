#include "AudioLoader.h"

void AudioLoader::LoadMusic(std::string filename)
{
	music_ = std::make_unique<sf::Music>();
	music_->openFromFile(filename);
}

void AudioLoader::PlayMusic() const
{
	music_->play();
}
