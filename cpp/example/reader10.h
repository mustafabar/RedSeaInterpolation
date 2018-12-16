#include "scalarfield.h"
static ScalarField sfu[10] = {
	YAML::LoadFile("yaml_files/u1.yaml"),
	YAML::LoadFile("yaml_files/u2.yaml"),
	YAML::LoadFile("yaml_files/u3.yaml"),
	YAML::LoadFile("yaml_files/u4.yaml"),
	YAML::LoadFile("yaml_files/u5.yaml"),
	YAML::LoadFile("yaml_files/u6.yaml"),
	YAML::LoadFile("yaml_files/u7.yaml"),
	YAML::LoadFile("yaml_files/u8.yaml"),
	YAML::LoadFile("yaml_files/u9.yaml"),
	YAML::LoadFile("yaml_files/u10.yaml")
};
static ScalarField sfv[10] = {
	YAML::LoadFile("yaml_files/v1.yaml"),
	YAML::LoadFile("yaml_files/v2.yaml"),
	YAML::LoadFile("yaml_files/v3.yaml"),
	YAML::LoadFile("yaml_files/v4.yaml"),
	YAML::LoadFile("yaml_files/v5.yaml"),
	YAML::LoadFile("yaml_files/v6.yaml"),
	YAML::LoadFile("yaml_files/v7.yaml"),
	YAML::LoadFile("yaml_files/v8.yaml"),
	YAML::LoadFile("yaml_files/v9.yaml"),
	YAML::LoadFile("yaml_files/v10.yaml")
};
static ScalarField sfw[10] = {
	YAML::LoadFile("yaml_files/w1.yaml"),
	YAML::LoadFile("yaml_files/w2.yaml"),
	YAML::LoadFile("yaml_files/w3.yaml"),
	YAML::LoadFile("yaml_files/w4.yaml"),
	YAML::LoadFile("yaml_files/w5.yaml"),
	YAML::LoadFile("yaml_files/w6.yaml"),
	YAML::LoadFile("yaml_files/w7.yaml"),
	YAML::LoadFile("yaml_files/w8.yaml"),
	YAML::LoadFile("yaml_files/w9.yaml"),
	YAML::LoadFile("yaml_files/w10.yaml")
};
static ScalarField sfcharac[10] = {
	YAML::LoadFile("yaml_files/charac1.yaml"),
	YAML::LoadFile("yaml_files/charac2.yaml"),
	YAML::LoadFile("yaml_files/charac3.yaml"),
	YAML::LoadFile("yaml_files/charac4.yaml"),
	YAML::LoadFile("yaml_files/charac5.yaml"),
	YAML::LoadFile("yaml_files/charac6.yaml"),
	YAML::LoadFile("yaml_files/charac7.yaml"),
	YAML::LoadFile("yaml_files/charac8.yaml"),
	YAML::LoadFile("yaml_files/charac9.yaml"),
	YAML::LoadFile("yaml_files/charac10.yaml")
};
