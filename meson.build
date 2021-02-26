project('Calculator_NX', ['c', 'cpp'],
    version: '1.3.0',
    default_options: [ 'buildtype=release', 'strip=true', 'b_ndebug=if-release', 'cpp_std=c++1z' ],
)

subdir('borealis/library')

demo_files = files(
    'source/main.cpp',

    'source/mainActivity.cpp',

    'source/calculatorTab.cpp',

    'source/calculator.cpp'
)

Calculator_NX = executable(
    'Calculator_NX',
    [ demo_files, borealis_files ],
    dependencies : borealis_dependencies,
    install: true,
    include_directories: [ borealis_include, include_directories('include')],
    cpp_args: [ '-g', '-O2', '-DBRLS_RESOURCES="resources/"', ] + borealis_cpp_args
)
