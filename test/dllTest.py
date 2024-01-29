import ctypes

neuro_dll = ctypes.CDLL('./cmake-build-debug/neuro/libneuro.dll')

neuro_dll.helloNeuro.restype = ctypes.c_char_p

hello_string = neuro_dll.helloNeuro().decode('utf-8')
print(hello_string)