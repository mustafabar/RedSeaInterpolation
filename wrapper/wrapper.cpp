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


EXTRFUNC_DECL_FUNCCALL(u);
EXTRFUNC_DECL_FUNCCALL(v);
EXTRFUNC_DECL_FUNCCALL(w);
EXTRFUNC_DECL_FUNCCALL(charac);


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


#define __FUNCNAME__ "u"
EXTRFUNC_DECL_FUNCCALL(u)
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
  auto result = sfu(p);
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


#define __FUNCNAME__ "v"
EXTRFUNC_DECL_FUNCCALL(v)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfv(p);
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


#define __FUNCNAME__ "w"
EXTRFUNC_DECL_FUNCCALL(w)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfw(p);
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

#define __FUNCNAME__ "charac"
EXTRFUNC_DECL_FUNCCALL(charac)
{
  char msg[256];

  if (3 != nargs) {
    sprintf (msg+1, "%s: 3 arguments expected.  Called with %d", __FUNCNAME__, nargs);
    msg[0] = strlen(msg+1);
    return errorcallback(EXTRFUNC_RETURN_SYSTEM, EXTRFUNC_ERROR_UNSPECIFIED,
                         msg, errorcbmem);
  }
  Point p(x[0], x[1], x[2]);
  auto result = sfcharac(p);
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

