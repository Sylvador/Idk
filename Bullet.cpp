#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::Bullet(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed)
{
	this->shape.setTexture(*texture);
	this->shape.setOrigin(this->shape.getGlobalBounds().width / 2, this->shape.getGlobalBounds().height / 2);
	this->shape.setScale(0.02f, 0.02f);

	this->shape.setPosition(pos_x, pos_y);
	this->direction.x = dir_x;
	this->direction.y = dir_y;
	this->movementSpeed = movement_speed;
}

Bullet::~Bullet()
{
}

const sf::FloatRect Bullet::getBounds() const
{
	return this->shape.getGlobalBounds();
}

void Bullet::update()
{
	//Movement
	this->shape.move(this->movementSpeed * this->direction);
	this->shape.rotate(10.f);
}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
