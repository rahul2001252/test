#ifndef _STRUCT_POOL_TEST_H_
#define _STRUCT_POOL_TEST_H_

#define VTX_CNT 4

#define DESC_LEN 31

#define MAX_POOL_SIZE 512

typedef struct Point_t
{
  int x;
  int y;
}Point;

typedef struct Rectangle_t
{
  Point v[VTX_CNT];
  char desc[DESC_LEN+1];
  int id;
  int pool_index;
  struct Rectangle_t *next;
}Rectangle;

#endif
