#include "scalarfield.h"

static ScalarField sfu(YAML::LoadFile("u.yaml"));
static ScalarField sfv(YAML::LoadFile("v.yaml"));
static ScalarField sfw(YAML::LoadFile("w.yaml"));
static ScalarField sfcharac(YAML::LoadFile("charac.yaml"));
