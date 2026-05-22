#pragma once

// Enumeração para os tipos de entidades no jogo, em vez de só guardar ids
// aleatórios
enum EntityType : char {
  ET_COLLECTABLE,
  ET_OBSTACLE,
  ET_PLAYER,
  ET_PROJECTABLE,
  ET_UNKNOWN
};

enum CollectableType : char { CT_BONE, CT_UNKNOWN };

enum ObstacleType : char { OT_MUSHROOM, OT_FIRE, OT_PLATAFORM, OT_UNKNOWN };

enum PersonagemType : char { PT_ENEMY, PT_PLAYER, PT_UNKNOWN };

enum ProjectableType : char { PJ_LASERBALL, PJ_UNKNOWN };

enum EnemyType : char {
  EN_TANYSTROPHEUS,
  EN_VELOCIRAPTOR,
  EN_MAMENCHISSAURO,
  EN_UNKNOWN
};
