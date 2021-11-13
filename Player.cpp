#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 5.f;

	this->attackCooldownMax = 10.f;
	this->attackCooldown = this->attackCooldownMax;

	this->hpMax = 100;
	this->hp = this->hpMax;
}

void Player::initTexture()
{
	if (!this->texture.loadFromFile("Images/Player.png"))
		std::cout << "ne, nihuya ne player";
}

void Player::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(0.2f, 0.2f);
}

Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{

}

void Player::setPosition(const sf::Vector2f pos)
{
	this->sprite.setPosition(pos);
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Player::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}

const sf::Vector2f& Player::getPos() const
{
	return this->sprite.getPosition();
}

const sf::Vector2f& Player::getSize() const
{
	return sf::Vector2f(this->sprite.getGlobalBounds().width, this->sprite.getGlobalBounds().height);
}

const sf::FloatRect Player::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& Player::getHp() const
{
	return this->hp;
}

const int& Player::getHpMax() const
{
	return this->hpMax;
}

void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}
	return false;
}

void Player::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
		this->attackCooldown += 0.5f;
}

//Functions
void Player::update()
{
	this->updateAttack();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
