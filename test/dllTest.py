import ctypes


neuro_dll = ctypes.CDLL("./cmake-build-debug/neuro/libneuro.dll")
#
# neuro_dll.getImageDataset.argtypes = [ctypes.POINTER(ctypes.c_char_p), ctypes.POINTER(ctypes.c_char_p)]
# neuro_dll.getImageDataset.restype = ctypes.c_void_p
#
# paths = ["C:\\Users\\Esilff\\Git\\ImageScrapper\\data\\moba",
#          "C:\\Users\\Esilff\\Git\\ImageScrapper\\data\\fps",
#          "C:\\Users\\Esilff\\Git\\ImageScrapper\\data\\rts"
#          ]
# categories = ["moba", "fps", "rts"]
#
# paths_array = (ctypes.c_char_p * len(paths))(*paths)
# categories_array = (ctypes.c_char_p * len(categories))(*categories)
#
# result_ptr = neuro_dll.getImageDataset(paths_array, categories_array)
#
# hello_string = neuro_dll.helloNeuro().decode('utf-8')