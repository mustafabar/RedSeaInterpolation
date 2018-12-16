/* QueryLibrary for wrappercclib
 * This file is created by ql.py.
 */

#include <stdlib.h>

#include "extrfunc.h"

/** Callback function to query function library functionality */
EXTRFUNC_API int EXTRFUNC_CALLCONV querylibrary(
   int                   funcnr,          /**< function number, or <= 0 for library query */
   int                   query,           /**< query number (either EXTRFUNC_LIBQUERY or EXTRFUNC_FUNCQUERY) */
   int*                  iv,              /**< buffer to store integer result */
   const char**          pv               /**< buffer to store string result (as C string!) */
   )
{
   *iv = -1;
   *pv = "Bad parameter(s)";

   if( funcnr <= 0 )
   {
      switch( (EXTRFUNC_LIBQUERY)query )
      {
         case EXTRFUNC_LIBQUERY_API :
            *iv = 2;
            *pv = NULL;
            break;

         case EXTRFUNC_LIBQUERY_LIBRARY :
            *iv = 1;
            *pv = "GAMS Development Corporation";
            break;

         case EXTRFUNC_LIBQUERY_NFUNCTIONS :
            *iv = 4;
            *pv = "Example C++ library with a simple function";
            break;

         case EXTRFUNC_LIBQUERY_NEEDLICENSE :
            *iv = 0;
            *pv = NULL;
            break;

         default :
            return EXTRFUNC_QUERYRETURN_ERROR;
      }

      return EXTRFUNC_QUERYRETURN_OK;
   }
   
   switch( funcnr )
   {
      case 1:  /* u */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "u";
               break;

            case EXTRFUNC_FUNCQUERY_FUNCDESCR :
               *iv = 0;
               *pv = "Velocity along axis x";
               break;

            case EXTRFUNC_FUNCQUERY_NOTINEQU :
               *iv = 0;
               *pv = NULL;
               break;

            case EXTRFUNC_FUNCQUERY_CONTINDERIV :
               *iv = 1;
               *pv = NULL;
               break;

            case EXTRFUNC_FUNCQUERY_ZERORIPPLE :
               *iv = 0;
               *pv = NULL;
               break;

            case EXTRFUNC_FUNCQUERY_ARGMIN :
               *iv = 3;
               *pv = NULL;
               break;

            case EXTRFUNC_FUNCQUERY_ARGMAX :
               *iv = 3;
               *pv = NULL;
               break;

            case EXTRFUNC_FUNCQUERY_MAXDERIV :
               *iv = 2;
               *pv = NULL;
               break;

            case EXTRFUNC_FUNCQUERY_ARG01 :
               *iv = 1;
               *pv = "x";
               break;
            case EXTRFUNC_FUNCQUERY_ARG02 :
               *iv = 1;
               *pv = "y";
               break;
            case EXTRFUNC_FUNCQUERY_ARG03 :
               *iv = 1;
               *pv = "z";
               break;
            default :
               return EXTRFUNC_QUERYRETURN_ERROR;
         }
         break;
      case 2:  /* v */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "v";
               break;

            case EXTRFUNC_FUNCQUERY_FUNCDESCR :
               *iv = 0;
               *pv = "Velocity along axis y";
               break;

            case EXTRFUNC_FUNCQUERY_NOTINEQU :
               *iv = 0;
               *pv = NULL;
               break;

            case EXTRFUNC_FUNCQUERY_CONTINDERIV :
               *iv = 1;
               *pv = NULL;
               break;

            case EXTRFUNC_FUNCQUERY_ZERORIPPLE :
               *iv = 0;
               *pv = NULL;
               break;

            case EXTRFUNC_FUNCQUERY_ARGMIN :
               *iv = 3;
               *pv = NULL;
               break;

            case EXTRFUNC_FUNCQUERY_ARGMAX :
               *iv = 3;
               *pv = NULL;
               break;

            case EXTRFUNC_FUNCQUERY_MAXDERIV :
               *iv = 2;
               *pv = NULL;
               break;

            case EXTRFUNC_FUNCQUERY_ARG01 :
               *iv = 1;
               *pv = "x";
               break;
            case EXTRFUNC_FUNCQUERY_ARG02 :
               *iv = 1;
               *pv = "y";
               break;
            case EXTRFUNC_FUNCQUERY_ARG03 :
               *iv = 1;
               *pv = "z";
               break;
            default :
               return EXTRFUNC_QUERYRETURN_ERROR;
         }
         break;
      case 3:  /* w */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "w";
               break;

            case EXTRFUNC_FUNCQUERY_FUNCDESCR :
               *iv = 0;
               *pv = "Velocity along axis z";
               break;

            case EXTRFUNC_FUNCQUERY_NOTINEQU :
               *iv = 0;
               *pv = NULL;
               break;

            case EXTRFUNC_FUNCQUERY_CONTINDERIV :
               *iv = 1;
               *pv = NULL;
               break;

            case EXTRFUNC_FUNCQUERY_ZERORIPPLE :
               *iv = 0;
               *pv = NULL;
               break;

            case EXTRFUNC_FUNCQUERY_ARGMIN :
               *iv = 3;
               *pv = NULL;
               break;

            case EXTRFUNC_FUNCQUERY_ARGMAX :
               *iv = 3;
               *pv = NULL;
               break;

            case EXTRFUNC_FUNCQUERY_MAXDERIV :
               *iv = 2;
               *pv = NULL;
               break;

            case EXTRFUNC_FUNCQUERY_ARG01 :
               *iv = 1;
               *pv = "x";
               break;
            case EXTRFUNC_FUNCQUERY_ARG02 :
               *iv = 1;
               *pv = "y";
               break;
            case EXTRFUNC_FUNCQUERY_ARG03 :
               *iv = 1;
               *pv = "z";
               break;
            default :
               return EXTRFUNC_QUERYRETURN_ERROR;
         }
         break;
      case 4:  /* charac */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "charac";
               break;

            case EXTRFUNC_FUNCQUERY_FUNCDESCR :
               *iv = 0;
               *pv = "Characteristic function";
               break;

            case EXTRFUNC_FUNCQUERY_NOTINEQU :
               *iv = 0;
               *pv = NULL;
               break;

            case EXTRFUNC_FUNCQUERY_CONTINDERIV :
               *iv = 1;
               *pv = NULL;
               break;

            case EXTRFUNC_FUNCQUERY_ZERORIPPLE :
               *iv = 0;
               *pv = NULL;
               break;

            case EXTRFUNC_FUNCQUERY_ARGMIN :
               *iv = 3;
               *pv = NULL;
               break;

            case EXTRFUNC_FUNCQUERY_ARGMAX :
               *iv = 3;
               *pv = NULL;
               break;

            case EXTRFUNC_FUNCQUERY_MAXDERIV :
               *iv = 2;
               *pv = NULL;
               break;

            case EXTRFUNC_FUNCQUERY_ARG01 :
               *iv = 1;
               *pv = "x";
               break;
            case EXTRFUNC_FUNCQUERY_ARG02 :
               *iv = 1;
               *pv = "y";
               break;
            case EXTRFUNC_FUNCQUERY_ARG03 :
               *iv = 1;
               *pv = "z";
               break;
            default :
               return EXTRFUNC_QUERYRETURN_ERROR;
         }
         break;
      default:
         return EXTRFUNC_QUERYRETURN_ERROR;
   }

   return EXTRFUNC_QUERYRETURN_OK;
}   
