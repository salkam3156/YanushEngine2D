#include "AudioLoader.h"

void AudioLoader::LoadMusic(std::string filename)
{
	music_ = std::make_unique<sf::Music>();
	music_->openFromFile(filename);
	music_->setMinDistance(0.1f);
	music_->setAttenuation(100000.f);
	SetMusicOriginLocation({ 0,0 });
}

void AudioLoader::PlayMusic() const
{
	//TODO: uncomment after debugging
	//music_->play();
}


void AudioLoader::SetMusicOriginLocation(sf::Vector2f location)
{
	music_->setRelativeToListener(true);
	music_->setPosition(location.x, location.y, 0);
}