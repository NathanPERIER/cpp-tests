
stdlib_test_apps = [
    'math/cast.cc'
]


foreach main_path : stdlib_test_apps
    test_name = main_path.substring(0, -3).replace('/', '-') + '-test'
    test_exe = executable(
        test_name, [main_path],
        dependencies: [fmt_dep, catch2_dep],
        install: false,
        build_by_default: true
    )
    test(test_name, test_exe)
endforeach

