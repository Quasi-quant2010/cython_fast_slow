/* File: matmult_f2pymodule.c
 * This file is auto-generated with f2py (version:2).
 * f2py is a Fortran to Python Interface Generator (FPIG), Second Edition,
 * written by Pearu Peterson <pearu@cens.ioc.ee>.
 * See http://cens.ioc.ee/projects/f2py2e/
 * Generation date: Tue Dec 17 02:26:06 2013
 * $Revision:$
 * $Date:$
 * Do not edit this file directly unless you know what you are doing!!!
 */
#ifdef __cplusplus
extern "C" {
#endif

/*********************** See f2py2e/cfuncs.py: includes ***********************/
#include "Python.h"
#include <stdarg.h>
#include "fortranobject.h"
#include <math.h>

/**************** See f2py2e/rules.py: mod_rules['modulebody'] ****************/
static PyObject *matmult_f2py_error;
static PyObject *matmult_f2py_module;

/*********************** See f2py2e/cfuncs.py: typedefs ***********************/
/*need_typedefs*/

/****************** See f2py2e/cfuncs.py: typedefs_generated ******************/
/*need_typedefs_generated*/

/********************** See f2py2e/cfuncs.py: cppmacros **********************/
#if defined(PREPEND_FORTRAN)
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F
#else
#define F_FUNC(f,F) _##f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F##_
#else
#define F_FUNC(f,F) _##f##_
#endif
#endif
#else
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F
#else
#define F_FUNC(f,F) f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F##_
#else
#define F_FUNC(f,F) f##_
#endif
#endif
#endif
#if defined(UNDERSCORE_G77)
#define F_FUNC_US(f,F) F_FUNC(f##_,F##_)
#else
#define F_FUNC_US(f,F) F_FUNC(f,F)
#endif

#define rank(var) var ## _Rank
#define shape(var,dim) var ## _Dims[dim]
#define old_rank(var) (((PyArrayObject *)(capi_ ## var ## _tmp))->nd)
#define old_shape(var,dim) (((PyArrayObject *)(capi_ ## var ## _tmp))->dimensions[dim])
#define fshape(var,dim) shape(var,rank(var)-dim-1)
#define len(var) shape(var,0)
#define flen(var) fshape(var,0)
#define old_size(var) PyArray_SIZE((PyArrayObject *)(capi_ ## var ## _tmp))
/* #define index(i) capi_i ## i */
#define slen(var) capi_ ## var ## _len
#define size(var, ...) f2py_size((PyArrayObject *)(capi_ ## var ## _tmp), ## __VA_ARGS__, -1)

#define CHECKSCALAR(check,tcheck,name,show,var)\
  if (!(check)) {\
    char errstring[256];\
    sprintf(errstring, "%s: "show, "("tcheck") failed for "name, var);\
    PyErr_SetString(matmult_f2py_error,errstring);\
    /*goto capi_fail;*/\
  } else 
#ifdef DEBUGCFUNCS
#define CFUNCSMESS(mess) fprintf(stderr,"debug-capi:"mess);
#define CFUNCSMESSPY(mess,obj) CFUNCSMESS(mess) \
  PyObject_Print((PyObject *)obj,stderr,Py_PRINT_RAW);\
  fprintf(stderr,"\n");
#else
#define CFUNCSMESS(mess)
#define CFUNCSMESSPY(mess,obj)
#endif

#ifndef max
#define max(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef min
#define min(a,b) ((a < b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef MIN
#define MIN(a,b) ((a < b) ? (a) : (b))
#endif


/************************ See f2py2e/cfuncs.py: cfuncs ************************/
int f2py_size(PyArrayObject* var, ...)
{
  npy_int sz = 0;
  npy_int dim;
  npy_int rank;
  va_list argp;
  va_start(argp, var);
  dim = va_arg(argp, npy_int);
  if (dim==-1)
    {
      sz = PyArray_SIZE(var);
    }
  else
    {
      rank = PyArray_NDIM(var);
      if (dim>=1 && dim<=rank)
        sz = PyArray_DIM(var, dim-1);
      else
        fprintf(stderr, "f2py_size: 2nd argument value=%d fails to satisfy 1<=value<=%d. Result will be 0.\n", dim, rank);
    }
  va_end(argp);
  return sz;
}

static int int_from_pyobj(int* v,PyObject *obj,const char *errmess) {
  PyObject* tmp = NULL;
  if (PyInt_Check(obj)) {
    *v = (int)PyInt_AS_LONG(obj);
    return 1;
  }
  tmp = PyNumber_Int(obj);
  if (tmp) {
    *v = PyInt_AS_LONG(tmp);
    Py_DECREF(tmp);
    return 1;
  }
  if (PyComplex_Check(obj))
    tmp = PyObject_GetAttrString(obj,"real");
  else if (PyString_Check(obj) || PyUnicode_Check(obj))
    /*pass*/;
  else if (PySequence_Check(obj))
    tmp = PySequence_GetItem(obj,0);
  if (tmp) {
    PyErr_Clear();
    if (int_from_pyobj(v,tmp,errmess)) {Py_DECREF(tmp); return 1;}
    Py_DECREF(tmp);
  }
  {
    PyObject* err = PyErr_Occurred();
    if (err==NULL) err = matmult_f2py_error;
    PyErr_SetString(err,errmess);
  }
  return 0;
}


/********************* See f2py2e/cfuncs.py: userincludes *********************/
/*need_userincludes*/

/********************* See f2py2e/capi_rules.py: usercode *********************/


/* See f2py2e/rules.py */
extern void F_FUNC_US(matmult_f,MATMULT_F)(int*,int*,int*,double*,double*,double*);
extern void matmult_c(int,int,int,double*,double*,double*);
/*eof externroutines*/

/******************** See f2py2e/capi_rules.py: usercode1 ********************/


/******************* See f2py2e/cb_rules.py: buildcallback *******************/
/*need_callbacks*/

/*********************** See f2py2e/rules.py: buildapi ***********************/

/********************************* matmult_f *********************************/
static char doc_f2py_rout_matmult_f2py_matmult_f[] = "\
Function signature:\n\
  c = matmult_f(a,b,[n,m,l])\n\
Required arguments:\n"
"  a : input rank-2 array('d') with bounds (n,l)\n"
"  b : input rank-2 array('d') with bounds (l,m)\n"
"Optional arguments:\n"
"  n := shape(a,0) input int\n"
"  m := shape(b,1) input int\n"
"  l := shape(a,1) input int\n"
"Return objects:\n"
"  c : rank-2 array('d') with bounds (n,m)";
/* extern void F_FUNC_US(matmult_f,MATMULT_F)(int*,int*,int*,double*,double*,double*); */
static PyObject *f2py_rout_matmult_f2py_matmult_f(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(int*,int*,int*,double*,double*,double*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  int n = 0;
  PyObject *n_capi = Py_None;
  int m = 0;
  PyObject *m_capi = Py_None;
  int l = 0;
  PyObject *l_capi = Py_None;
  double *a = NULL;
  npy_intp a_Dims[2] = {-1, -1};
  const int a_Rank = 2;
  PyArrayObject *capi_a_tmp = NULL;
  int capi_a_intent = 0;
  PyObject *a_capi = Py_None;
  double *b = NULL;
  npy_intp b_Dims[2] = {-1, -1};
  const int b_Rank = 2;
  PyArrayObject *capi_b_tmp = NULL;
  int capi_b_intent = 0;
  PyObject *b_capi = Py_None;
  double *c = NULL;
  npy_intp c_Dims[2] = {-1, -1};
  const int c_Rank = 2;
  PyArrayObject *capi_c_tmp = NULL;
  int capi_c_intent = 0;
  static char *capi_kwlist[] = {"a","b","n","m","l",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OO|OOO:matmult_f2py.matmult_f",\
    capi_kwlist,&a_capi,&b_capi,&n_capi,&m_capi,&l_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable a */
  ;
  capi_a_intent |= F2PY_INTENT_IN;
  capi_a_tmp = array_from_pyobj(PyArray_DOUBLE,a_Dims,a_Rank,capi_a_intent,a_capi);
  if (capi_a_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(matmult_f2py_error,"failed in converting 1st argument `a' of matmult_f2py.matmult_f to C/Fortran array" );
  } else {
    a = (double *)(capi_a_tmp->data);

  /* Processing variable l */
  if (l_capi == Py_None) l = shape(a,1); else
    f2py_success = int_from_pyobj(&l,l_capi,"matmult_f2py.matmult_f() 3rd keyword (l) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(a,1)==l,"shape(a,1)==l","3rd keyword l","matmult_f:l=%d",l) {
  /* Processing variable n */
  if (n_capi == Py_None) n = shape(a,0); else
    f2py_success = int_from_pyobj(&n,n_capi,"matmult_f2py.matmult_f() 1st keyword (n) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(a,0)==n,"shape(a,0)==n","1st keyword n","matmult_f:n=%d",n) {
  /* Processing variable b */
  b_Dims[0]=l;
  capi_b_intent |= F2PY_INTENT_IN;
  capi_b_tmp = array_from_pyobj(PyArray_DOUBLE,b_Dims,b_Rank,capi_b_intent,b_capi);
  if (capi_b_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(matmult_f2py_error,"failed in converting 2nd argument `b' of matmult_f2py.matmult_f to C/Fortran array" );
  } else {
    b = (double *)(capi_b_tmp->data);

  /* Processing variable m */
  if (m_capi == Py_None) m = shape(b,1); else
    f2py_success = int_from_pyobj(&m,m_capi,"matmult_f2py.matmult_f() 2nd keyword (m) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(b,1)==m,"shape(b,1)==m","2nd keyword m","matmult_f:m=%d",m) {
  /* Processing variable c */
  c_Dims[0]=n,c_Dims[1]=m;
  capi_c_intent |= F2PY_INTENT_OUT|F2PY_INTENT_HIDE;
  capi_c_tmp = array_from_pyobj(PyArray_DOUBLE,c_Dims,c_Rank,capi_c_intent,Py_None);
  if (capi_c_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(matmult_f2py_error,"failed in converting hidden `c' of matmult_f2py.matmult_f to C/Fortran array" );
  } else {
    c = (double *)(capi_c_tmp->data);

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(&n,&m,&l,a,b,c);
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("N",capi_c_tmp);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  }  /*if (capi_c_tmp == NULL) ... else of c*/
  /* End of cleaning variable c */
  } /*CHECKSCALAR(shape(b,1)==m)*/
  } /*if (f2py_success) of m*/
  /* End of cleaning variable m */
  if((PyObject *)capi_b_tmp!=b_capi) {
    Py_XDECREF(capi_b_tmp); }
  }  /*if (capi_b_tmp == NULL) ... else of b*/
  /* End of cleaning variable b */
  } /*CHECKSCALAR(shape(a,0)==n)*/
  } /*if (f2py_success) of n*/
  /* End of cleaning variable n */
  } /*CHECKSCALAR(shape(a,1)==l)*/
  } /*if (f2py_success) of l*/
  /* End of cleaning variable l */
  if((PyObject *)capi_a_tmp!=a_capi) {
    Py_XDECREF(capi_a_tmp); }
  }  /*if (capi_a_tmp == NULL) ... else of a*/
  /* End of cleaning variable a */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/****************************** end of matmult_f ******************************/

/********************************* matmult_c *********************************/
static char doc_f2py_rout_matmult_f2py_matmult_c[] = "\
Function signature:\n\
  c = matmult_c(a,b,[n,m,l])\n\
Required arguments:\n"
"  a : input rank-2 array('d') with bounds (n,l)\n"
"  b : input rank-2 array('d') with bounds (l,m)\n"
"Optional arguments:\n"
"  n := shape(a,0) input int\n"
"  m := shape(b,1) input int\n"
"  l := shape(a,1) input int\n"
"Return objects:\n"
"  c : rank-2 array('d') with bounds (n,m)";
/* extern void matmult_c(int,int,int,double*,double*,double*); */
static PyObject *f2py_rout_matmult_f2py_matmult_c(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(int,int,int,double*,double*,double*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  int n = 0;
  PyObject *n_capi = Py_None;
  int m = 0;
  PyObject *m_capi = Py_None;
  int l = 0;
  PyObject *l_capi = Py_None;
  double *a = NULL;
  npy_intp a_Dims[2] = {-1, -1};
  const int a_Rank = 2;
  PyArrayObject *capi_a_tmp = NULL;
  int capi_a_intent = 0;
  PyObject *a_capi = Py_None;
  double *b = NULL;
  npy_intp b_Dims[2] = {-1, -1};
  const int b_Rank = 2;
  PyArrayObject *capi_b_tmp = NULL;
  int capi_b_intent = 0;
  PyObject *b_capi = Py_None;
  double *c = NULL;
  npy_intp c_Dims[2] = {-1, -1};
  const int c_Rank = 2;
  PyArrayObject *capi_c_tmp = NULL;
  int capi_c_intent = 0;
  static char *capi_kwlist[] = {"a","b","n","m","l",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OO|OOO:matmult_f2py.matmult_c",\
    capi_kwlist,&a_capi,&b_capi,&n_capi,&m_capi,&l_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable a */
  ;
  capi_a_intent |= F2PY_INTENT_C|F2PY_INTENT_IN;
  capi_a_tmp = array_from_pyobj(PyArray_DOUBLE,a_Dims,a_Rank,capi_a_intent,a_capi);
  if (capi_a_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(matmult_f2py_error,"failed in converting 1st argument `a' of matmult_f2py.matmult_c to C/Fortran array" );
  } else {
    a = (double *)(capi_a_tmp->data);

  /* Processing variable l */
  if (l_capi == Py_None) l = shape(a,1); else
    f2py_success = int_from_pyobj(&l,l_capi,"matmult_f2py.matmult_c() 3rd keyword (l) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(a,1)==l,"shape(a,1)==l","3rd keyword l","matmult_c:l=%d",l) {
  /* Processing variable n */
  if (n_capi == Py_None) n = shape(a,0); else
    f2py_success = int_from_pyobj(&n,n_capi,"matmult_f2py.matmult_c() 1st keyword (n) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(a,0)==n,"shape(a,0)==n","1st keyword n","matmult_c:n=%d",n) {
  /* Processing variable b */
  b_Dims[0]=l;
  capi_b_intent |= F2PY_INTENT_C|F2PY_INTENT_IN;
  capi_b_tmp = array_from_pyobj(PyArray_DOUBLE,b_Dims,b_Rank,capi_b_intent,b_capi);
  if (capi_b_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(matmult_f2py_error,"failed in converting 2nd argument `b' of matmult_f2py.matmult_c to C/Fortran array" );
  } else {
    b = (double *)(capi_b_tmp->data);

  /* Processing variable m */
  if (m_capi == Py_None) m = shape(b,1); else
    f2py_success = int_from_pyobj(&m,m_capi,"matmult_f2py.matmult_c() 2nd keyword (m) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(b,1)==m,"shape(b,1)==m","2nd keyword m","matmult_c:m=%d",m) {
  /* Processing variable c */
  c_Dims[0]=n,c_Dims[1]=m;
  capi_c_intent |= F2PY_INTENT_OUT|F2PY_INTENT_HIDE|F2PY_INTENT_C;
  capi_c_tmp = array_from_pyobj(PyArray_DOUBLE,c_Dims,c_Rank,capi_c_intent,Py_None);
  if (capi_c_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(matmult_f2py_error,"failed in converting hidden `c' of matmult_f2py.matmult_c to C/Fortran array" );
  } else {
    c = (double *)(capi_c_tmp->data);

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(n,m,l,a,b,c);
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("N",capi_c_tmp);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  }  /*if (capi_c_tmp == NULL) ... else of c*/
  /* End of cleaning variable c */
  } /*CHECKSCALAR(shape(b,1)==m)*/
  } /*if (f2py_success) of m*/
  /* End of cleaning variable m */
  if((PyObject *)capi_b_tmp!=b_capi) {
    Py_XDECREF(capi_b_tmp); }
  }  /*if (capi_b_tmp == NULL) ... else of b*/
  /* End of cleaning variable b */
  } /*CHECKSCALAR(shape(a,0)==n)*/
  } /*if (f2py_success) of n*/
  /* End of cleaning variable n */
  } /*CHECKSCALAR(shape(a,1)==l)*/
  } /*if (f2py_success) of l*/
  /* End of cleaning variable l */
  if((PyObject *)capi_a_tmp!=a_capi) {
    Py_XDECREF(capi_a_tmp); }
  }  /*if (capi_a_tmp == NULL) ... else of a*/
  /* End of cleaning variable a */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/****************************** end of matmult_c ******************************/
/*eof body*/

/******************* See f2py2e/f90mod_rules.py: buildhooks *******************/
/*need_f90modhooks*/

/************** See f2py2e/rules.py: module_rules['modulebody'] **************/

/******************* See f2py2e/common_rules.py: buildhooks *******************/

/*need_commonhooks*/

/**************************** See f2py2e/rules.py ****************************/

static FortranDataDef f2py_routine_defs[] = {
  {"matmult_f",-1,{{-1}},0,(char *)F_FUNC_US(matmult_f,MATMULT_F),(f2py_init_func)f2py_rout_matmult_f2py_matmult_f,doc_f2py_rout_matmult_f2py_matmult_f},
  {"matmult_c",-1,{{-1}},0,(char *)matmult_c,(f2py_init_func)f2py_rout_matmult_f2py_matmult_c,doc_f2py_rout_matmult_f2py_matmult_c},

/*eof routine_defs*/
  {NULL}
};

static PyMethodDef f2py_module_methods[] = {

  {NULL,NULL}
};

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef moduledef = {
  PyModuleDef_HEAD_INIT,
  "matmult_f2py",
  NULL,
  -1,
  f2py_module_methods,
  NULL,
  NULL,
  NULL,
  NULL
};
#endif

#if PY_VERSION_HEX >= 0x03000000
#define RETVAL m
PyObject *PyInit_matmult_f2py(void) {
#else
#define RETVAL
PyMODINIT_FUNC initmatmult_f2py(void) {
#endif
  int i;
  PyObject *m,*d, *s;
#if PY_VERSION_HEX >= 0x03000000
  m = matmult_f2py_module = PyModule_Create(&moduledef);
#else
  m = matmult_f2py_module = Py_InitModule("matmult_f2py", f2py_module_methods);
#endif
  Py_TYPE(&PyFortran_Type) = &PyType_Type;
  import_array();
  if (PyErr_Occurred())
    {PyErr_SetString(PyExc_ImportError, "can't initialize module matmult_f2py (failed to import numpy)"); return RETVAL;}
  d = PyModule_GetDict(m);
  s = PyString_FromString("$Revision: $");
  PyDict_SetItemString(d, "__version__", s);
#if PY_VERSION_HEX >= 0x03000000
  s = PyUnicode_FromString(
#else
  s = PyString_FromString(
#endif
    "This module 'matmult_f2py' is auto-generated with f2py (version:2).\nFunctions:\n"
"  c = matmult_f(a,b,n=shape(a,0),m=shape(b,1),l=shape(a,1))\n"
"  c = matmult_c(a,b,n=shape(a,0),m=shape(b,1),l=shape(a,1))\n"
".");
  PyDict_SetItemString(d, "__doc__", s);
  matmult_f2py_error = PyErr_NewException ("matmult_f2py.error", NULL, NULL);
  Py_DECREF(s);
  for(i=0;f2py_routine_defs[i].name!=NULL;i++)
    PyDict_SetItemString(d, f2py_routine_defs[i].name,PyFortranObject_NewAsAttr(&f2py_routine_defs[i]));


/*eof initf2pywraphooks*/
/*eof initf90modhooks*/

/*eof initcommonhooks*/


#ifdef F2PY_REPORT_ATEXIT
  if (! PyErr_Occurred())
    on_exit(f2py_report_on_exit,(void*)"matmult_f2py");
#endif

  return RETVAL;
}
#ifdef __cplusplus
}
#endif
