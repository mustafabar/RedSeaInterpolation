#!/usr/bin/env sh
ctags -R -f .tags_eigen ~/local/opt/eigen/include/eigen3
ctags -R -f .tags_gmock ~/softwares/googletest/googlemock/include
ctags -R -f .tags_gtest ~/softwares/googletest/googletest/include
ctags -R -f .tags_yaml --exclude=gtest --exclude=gmock ~/local/opt/yaml-cpp/include/
