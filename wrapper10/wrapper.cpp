#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>

#include "extrfunc.h"
#include "reader.h"

#define CMPVER 1

struct EXTRFUNC_Data
{
  int dummy;
};


EXTRFUNC_DECL_FUNCCALL(u1);
EXTRFUNC_DECL_FUNCCALL(v1);
EXTRFUNC_DECL_FUNCCALL(w1);
EXTRFUNC_DECL_FUNCCALL(charac1);


EXTRFUNC_DECL_FUNCCALL(u2);
EXTRFUNC_DECL_FUNCCALL(v2);
EXTRFUNC_DECL_FUNCCALL(w2);
EXTRFUNC_DECL_FUNCCALL(charac2);

EXTRFUNC_DECL_FUNCCALL(u3);
EXTRFUNC_DECL_FUNCCALL(v3);
EXTRFUNC_DECL_FUNCCALL(w3);
EXTRFUNC_DECL_FUNCCALL(charac3);

EXTRFUNC_DECL_FUNCCALL(u4);
EXTRFUNC_DECL_FUNCCALL(v4);
EXTRFUNC_DECL_FUNCCALL(w4);
EXTRFUNC_DECL_FUNCCALL(charac4);

EXTRFUNC_DECL_FUNCCALL(u5);
EXTRFUNC_DECL_FUNCCALL(v5);
EXTRFUNC_DECL_FUNCCALL(w5);
EXTRFUNC_DECL_FUNCCALL(charac5);

EXTRFUNC_DECL_FUNCCALL(u6);
EXTRFUNC_DECL_FUNCCALL(v6);
EXTRFUNC_DECL_FUNCCALL(w6);
EXTRFUNC_DECL_FUNCCALL(charac6);

EXTRFUNC_DECL_FUNCCALL(u7);
EXTRFUNC_DECL_FUNCCALL(v7);
EXTRFUNC_DECL_FUNCCALL(w7);
EXTRFUNC_DECL_FUNCCALL(charac7);

EXTRFUNC_DECL_FUNCCALL(u8);
EXTRFUNC_DECL_FUNCCALL(v8);
EXTRFUNC_DECL_FUNCCALL(w8);
EXTRFUNC_DECL_FUNCCALL(charac8);


EXTRFUNC_DECL_FUNCCALL(u9);
EXTRFUNC_DECL_FUNCCALL(v9);
EXTRFUNC_DECL_FUNCCALL(w9);
EXTRFUNC_DECL_FUNCCALL(charac9);

EXTRFUNC_DECL_FUNCCALL(u10);
EXTRFUNC_DECL_FUNCCALL(v10);
EXTRFUNC_DECL_FUNCCALL(w10);
EXTRFUNC_DECL_FUNCCALL(charac10);


/**< buffer to store pointer to function library data structure */
EXTRFUNC_API void EXTRFUNC_CALLCONV xcreate(EXTRFUNC_DATA** data)
{
   *data = (EXTRFUNC_DATA*) malloc(sizeof(EXTRFUNC_DATA));
   assert(*data != NULL);
}

/**< pointer to pointer to function library data structure */
EXTRFUNC_API void EXTRFUNC_CALLCONV xfree(EXTRFUNC_DATA** data)
{
   if( data != NULL )
   {
      free(*data);
      *data = NULL;
   }
}


/*
  data: function library data structure
  version: version number
  msg: buffer of length 255 to store error message (as Delphi string!)
 */

EXTRFUNC_API int EXTRFUNC_CALLCONV libinit(EXTRFUNC_DATA* data, int version,
                                           char* msg)
{
   if( version < CMPVER )
   {
      sprintf(msg+1, "Client is too old for this Library.");
      msg[0] = strlen(msg+1);
      return 1;
   }
   return 0;
}



////////////////////////////////////////////////// SNAPSHOT 1 ///////////////////////////////////////////////////////////////
#define __FUNCNAME__ "u1"
EXTRFUNC_DECL_FUNCCALL(u1)
// wrappedU(x, y, z)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfu1(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // u
#undef __FUNCNAME__


#define __FUNCNAME__ "v1"
EXTRFUNC_DECL_FUNCCALL(v1)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfv1(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // v
#undef __FUNCNAME__


#define __FUNCNAME__ "w1"
EXTRFUNC_DECL_FUNCCALL(w1)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfw1(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // w
#undef __FUNCNAME__

#define __FUNCNAME__ "charac1"
EXTRFUNC_DECL_FUNCCALL(charac1)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfcharac1(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // w
#undef __FUNCNAME__







////////////////////////////////////////////////// SNAPSHOT 2 ///////////////////////////////////////////////////////////////
#define __FUNCNAME__ "u2"
EXTRFUNC_DECL_FUNCCALL(u2)
// wrappedU(x, y, z)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfu2(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // u
#undef __FUNCNAME__


#define __FUNCNAME__ "v2"
EXTRFUNC_DECL_FUNCCALL(v2)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfv2(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // v
#undef __FUNCNAME__


#define __FUNCNAME__ "w2"
EXTRFUNC_DECL_FUNCCALL(w2)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfw2(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // w
#undef __FUNCNAME__

#define __FUNCNAME__ "charac2"
EXTRFUNC_DECL_FUNCCALL(charac2)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfcharac2(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // w
#undef __FUNCNAME__







////////////////////////////////////////////////// SNAPSHOT 3 ///////////////////////////////////////////////////////////////
#define __FUNCNAME__ "u3"
EXTRFUNC_DECL_FUNCCALL(u3)
// wrappedU(x, y, z)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfu3(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // u
#undef __FUNCNAME__


#define __FUNCNAME__ "v3"
EXTRFUNC_DECL_FUNCCALL(v3)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfv3(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // v
#undef __FUNCNAME__


#define __FUNCNAME__ "w3"
EXTRFUNC_DECL_FUNCCALL(w3)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfw3(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // w
#undef __FUNCNAME__

#define __FUNCNAME__ "charac3"
EXTRFUNC_DECL_FUNCCALL(charac3)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfcharac3(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // w
#undef __FUNCNAME__







////////////////////////////////////////////////// SNAPSHOT 4 ///////////////////////////////////////////////////////////////
#define __FUNCNAME__ "u4"
EXTRFUNC_DECL_FUNCCALL(u4)
// wrappedU(x, y, z)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfu4(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // u
#undef __FUNCNAME__


#define __FUNCNAME__ "v4"
EXTRFUNC_DECL_FUNCCALL(v4)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfv4(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // v
#undef __FUNCNAME__


#define __FUNCNAME__ "w4"
EXTRFUNC_DECL_FUNCCALL(w4)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfw4(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // w
#undef __FUNCNAME__

#define __FUNCNAME__ "charac4"
EXTRFUNC_DECL_FUNCCALL(charac4)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfcharac4(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // w
#undef __FUNCNAME__







////////////////////////////////////////////////// SNAPSHOT 5 ///////////////////////////////////////////////////////////////
#define __FUNCNAME__ "u5"
EXTRFUNC_DECL_FUNCCALL(u5)
// wrappedU(x, y, z)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfu5(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // u
#undef __FUNCNAME__


#define __FUNCNAME__ "v5"
EXTRFUNC_DECL_FUNCCALL(v5)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfv5(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // v
#undef __FUNCNAME__


#define __FUNCNAME__ "w5"
EXTRFUNC_DECL_FUNCCALL(w5)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfw5(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // w
#undef __FUNCNAME__

#define __FUNCNAME__ "charac5"
EXTRFUNC_DECL_FUNCCALL(charac5)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfcharac5(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // w
#undef __FUNCNAME__







////////////////////////////////////////////////// SNAPSHOT 6 ///////////////////////////////////////////////////////////////
#define __FUNCNAME__ "u6"
EXTRFUNC_DECL_FUNCCALL(u6)
// wrappedU(x, y, z)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfu6(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // u
#undef __FUNCNAME__


#define __FUNCNAME__ "v6"
EXTRFUNC_DECL_FUNCCALL(v6)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfv6(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // v
#undef __FUNCNAME__


#define __FUNCNAME__ "w6"
EXTRFUNC_DECL_FUNCCALL(w6)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfw6(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // w
#undef __FUNCNAME__

#define __FUNCNAME__ "charac6"
EXTRFUNC_DECL_FUNCCALL(charac6)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfcharac6(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // w
#undef __FUNCNAME__







////////////////////////////////////////////////// SNAPSHOT 7 ///////////////////////////////////////////////////////////////
#define __FUNCNAME__ "u7"
EXTRFUNC_DECL_FUNCCALL(u7)
// wrappedU(x, y, z)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfu7(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // u
#undef __FUNCNAME__


#define __FUNCNAME__ "v7"
EXTRFUNC_DECL_FUNCCALL(v7)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfv7(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // v
#undef __FUNCNAME__


#define __FUNCNAME__ "w7"
EXTRFUNC_DECL_FUNCCALL(w7)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfw7(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // w
#undef __FUNCNAME__

#define __FUNCNAME__ "charac7"
EXTRFUNC_DECL_FUNCCALL(charac7)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfcharac7(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // w
#undef __FUNCNAME__







////////////////////////////////////////////////// SNAPSHOT 8 ///////////////////////////////////////////////////////////////
#define __FUNCNAME__ "u8"
EXTRFUNC_DECL_FUNCCALL(u8)
// wrappedU(x, y, z)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfu8(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // u
#undef __FUNCNAME__


#define __FUNCNAME__ "v8"
EXTRFUNC_DECL_FUNCCALL(v8)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfv8(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // v
#undef __FUNCNAME__


#define __FUNCNAME__ "w8"
EXTRFUNC_DECL_FUNCCALL(w8)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfw8(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // w
#undef __FUNCNAME__

#define __FUNCNAME__ "charac8"
EXTRFUNC_DECL_FUNCCALL(charac8)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfcharac8(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // w
#undef __FUNCNAME__







////////////////////////////////////////////////// SNAPSHOT 9 ///////////////////////////////////////////////////////////////
#define __FUNCNAME__ "u9"
EXTRFUNC_DECL_FUNCCALL(u9)
// wrappedU(x, y, z)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfu9(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // u
#undef __FUNCNAME__


#define __FUNCNAME__ "v9"
EXTRFUNC_DECL_FUNCCALL(v9)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfv9(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // v
#undef __FUNCNAME__


#define __FUNCNAME__ "w9"
EXTRFUNC_DECL_FUNCCALL(w9)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfw9(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // w
#undef __FUNCNAME__

#define __FUNCNAME__ "charac9"
EXTRFUNC_DECL_FUNCCALL(charac9)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfcharac9(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // w
#undef __FUNCNAME__







////////////////////////////////////////////////// SNAPSHOT 10 ///////////////////////////////////////////////////////////////
#define __FUNCNAME__ "u10"
EXTRFUNC_DECL_FUNCCALL(u10)
// wrappedU(x, y, z)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfu10(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // u
#undef __FUNCNAME__


#define __FUNCNAME__ "v10"
EXTRFUNC_DECL_FUNCCALL(v10)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfv10(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // v
#undef __FUNCNAME__


#define __FUNCNAME__ "w10"
EXTRFUNC_DECL_FUNCCALL(w10)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfw10(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // w
#undef __FUNCNAME__

#define __FUNCNAME__ "charac10"
EXTRFUNC_DECL_FUNCCALL(charac10)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfcharac10(p);
  *funcvalue = result.fun;
  if (derivrequest <= 0) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 3; i++) {
    gradient[i] = result.grad(i);
  }

  if (derivrequest <= 1) return EXTRFUNC_RETURN_OK;

  for (int i = 0; i < 9; i++) {
    hessian[i] = *(result.hess.data() + i);
  }

  return EXTRFUNC_RETURN_OK;
} // w
#undef __FUNCNAME__
