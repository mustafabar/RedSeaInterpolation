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
            *iv = 40;
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
               *pv = "u1";
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
               *pv = "v1";
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
               *pv = "w1";
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
               *pv = "charac1";
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

         case 5:  /* u */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "u2";
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
      case 6:  /* v */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "v2";
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
      case 7:  /* w */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "w2";
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
      case 8:  /* charac */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "charac2";
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



         case 9:  /* u */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "u3";
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
      case 10:  /* v */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "v3";
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
      case 11:  /* w */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "w3";
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
      case 12:  /* charac */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "charac3";
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

         case 13:  /* u */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "u4";
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
      case 14:  /* v */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "v4";
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
      case 15:  /* w */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "w4";
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
      case 16:  /* charac */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "charac4";
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
         case 17:  /* u */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "u5";
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
      case 18:  /* v */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "v5";
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
      case 19:  /* w */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "w5";
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
      case 20:  /* charac */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "charac5";
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
         case 21:  /* u */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "u6";
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
      case 22:  /* v */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "v6";
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
      case 23:  /* w */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "w6";
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
      case 24:  /* charac */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "charac6";
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

         case 25:  /* u */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "u7";
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
      case 26:  /* v */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "v7";
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
      case 27:  /* w */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "w7";
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
      case 28:  /* charac */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "charac7";
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

         case 29:  /* u */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "u8";
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
      case 30:  /* v */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "v8";
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
      case 31:  /* w */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "w8";
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
      case 32:  /* charac */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "charac8";
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



         case 33:  /* u */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "u9";
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
      case 34:  /* v */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "v9";
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
      case 35:  /* w */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "w9";
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
      case 36:  /* charac */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "charac9";
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



         case 37:  /* u */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "u10";
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
      case 38:  /* v */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "v10";
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
      case 39:  /* w */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "w10";
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
      case 40:  /* charac */
         switch( (EXTRFUNC_FUNCQUERY)query )
         {
            case EXTRFUNC_FUNCQUERY_FUNCNAME :
               *iv = 0;
               *pv = "charac10";
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
