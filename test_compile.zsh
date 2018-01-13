#!/usr/local/bin/zsh
for f in src/**/*.cpp; do
  c++ -g -Wall -Werror -Wswitch-default -Wswitch-enum -Wno-unused-parameter -Wno-c99-extensions -Wno-keyword-macro -Wno-reserved-id-macro -Wno-c++11-long-long -Weverything -Wno-disabled-macro-expansion -Wno-padded -Wno-global-constructors -Wno-exit-time-destructors -Wno-weak-vtables -Wno-old-style-cast -Wall -Werror -Wswitch-default -Wswitch-enum -Wno-unused-parameter -Wno-c99-extensions -Wno-keyword-macro -Wno-reserved-id-macro -Wno-c++11-long-long -c -MMD -MP -o objs/${f:r}.o ${f}
done
for f in tests/**/*.cpp; do
  c++ -g -Wall -Werror -Wswitch-default -Wswitch-enum -Wno-unused-parameter -Wno-c99-extensions -Wno-keyword-macro -Wno-reserved-id-macro -Wno-c++11-long-long -Weverything -Wno-disabled-macro-expansion -Wno-padded -Wno-global-constructors -Wno-exit-time-destructors -Wno-weak-vtables -Wno-old-style-cast -include /usr/local/Cellar/cpputest/3.8/include/CppUTest/MemoryLeakDetectorNewMacros.h  -DCPPUTEST_COMPILATION -Wall -Werror -Wswitch-default -Wswitch-enum -Wno-unused-parameter -Wno-c99-extensions -Wno-keyword-macro -Wno-reserved-id-macro -Wno-c++11-long-long -include /usr/local/Cellar/cpputest/3.8/include/CppUTest/MemoryLeakDetectorMallocMacros.h  -I/usr/local/Cellar/cpputest/3.8/include/  -Iinclude/led_driver  -Iinclude/traffic_light    -c -MMD -MP -o objs/${f:r}.o ${f}
done
