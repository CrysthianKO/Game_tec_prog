#pragma once

// Enumeração para os tipos de entidades no jogo, em vez de só guardar ids
// aleatórios
enum EntityType : char {
  ET_COLLECTABLE,
  ET_OBSTACLE,
  ET_CHARACTER,
  ET_PROJECTABLE,
  ET_UNKNOWN
};

enum CollectableType : char { CT_BONE, CT_UNKNOWN };

enum ObstacleType : char { OT_MUSHROOM, OT_FIRE, OT_PLATFORM, OT_UNKNOWN };

enum CharacterType : char { CH_ENEMY, CH_PLAYER, CH_UNKNOWN };

enum ProjectableType : char { PJ_LASERBALL, PJ_UNKNOWN };
enum EnemyType : char {
  EN_TANYSTROPHEUS,
  EN_PTERODACTYL,
  EN_VELOCIRAPTOR,
  EN_MAMENCHISSAURO,
  EN_UNKNOWN
};
