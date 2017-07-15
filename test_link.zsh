#!/usr/local/bin/zsh
c++ -o test_iso11783 objs/tests/**/*.o /usr/local/Cellar/cpputest/3.8/lib/libCppUTest.a /usr/local/Cellar/cpputest/3.8/lib/libCppUTestExt.a  -g
