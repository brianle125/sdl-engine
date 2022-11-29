#include "AssetManager.h"
#include "ECS\Components.h"

AssetManager::AssetManager(Manager* man)
{
	manager = man;
}

AssetManager::~AssetManager()
{}

void AssetManager::CreateProjectile(Vector2D pos, Vector2D vel, int range, int speed, std::string id)
{
	auto& projectile(manager->addEntity());
	projectile.addComponent<TransformComponent>(pos.x, pos.y, 32, 32, 1);
	projectile.addComponent<SpriteComponent>(id, false);
	projectile.addComponent<ProjectileComponent>(range, speed, vel);
	projectile.addComponent<ColliderComponent>("projectile");
	projectile.addGroup(Game::groupProjectiles);
}

void AssetManager::CreateEnemy(Vector2D pos, Vector2D vel, int w, int h, int sc, std::string id)
{
	auto& enemy(manager->addEntity());
	enemy.addComponent<TransformComponent>(pos.x, pos.y, w, h, sc);
	enemy.addComponent<SpriteComponent>(id, false);
	enemy.addComponent<EnemyMelee>(140, 2, vel);
	enemy.addComponent<ColliderComponent>("enemy");
	enemy.addGroup(Game::groupEnemies);
}

void AssetManager::CreateEnemy(Vector2D pos, int w, int h, int sc, std::string id)
{
	auto& enemy(manager->addEntity());
	enemy.addComponent<TransformComponent>(pos.x, pos.y, w, h, sc);
	enemy.addComponent<SpriteComponent>(id, false);
	enemy.addComponent<ColliderComponent>("enemy");
	enemy.addGroup(Game::groupEnemies);
}

void AssetManager::AddTexture(std::string id, const char* path)
{
	textures.emplace(id, TextureManager::LoadTexture(path));
}


SDL_Texture* AssetManager::GetTexture(std::string id)
{
	return textures[id];
}

void AssetManager::AddFont(std::string id, std::string path, int fontSize)
{
	fonts.emplace(id, TTF_OpenFont(path.c_str(), fontSize));
}
TTF_Font* AssetManager::GetFont(std::string id)
{
	return fonts[id];
}
