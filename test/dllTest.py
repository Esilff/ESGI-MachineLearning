import ctypes


neuro_dll = ctypes.CDLL("./cmake-build-release-visual-studio/neuro/neuro.dll")

neuro_dll.getImageDataset.argtypes = [ctypes.POINTER(ctypes.c_char_p), ctypes.POINTER(ctypes.c_char_p)]
neuro_dll.getImageDataset.restype = ctypes.c_void_p

neuro_dll.trainLinearRegression.argtypes = [ctypes.c_void_p, ctypes.c_float, ctypes.c_int]
neuro_dll.trainLinearRegression.restype = ctypes.c_void_p

neuro_dll.predictLinearRegression.argtypes = [ctypes.c_void_p, ctypes.c_void_p, ctypes.c_char_p]
neuro_dll.predictLinearRegression.restype = None

paths = [b"C:\\Users\\Esilff\\Git\\ImageScrapper\\data\\moba",
         b"C:\\Users\\Esilff\\Git\\ImageScrapper\\data\\fps",
         b"C:\\Users\\Esilff\\Git\\ImageScrapper\\data\\rts"
         ]
categories = [b"moba", b"fps", b"rts"]

paths_array = (ctypes.c_char_p * len(paths))(*paths)
categories_array = (ctypes.c_char_p * len(categories))(*categories)

result_ptr = neuro_dll.getImageDataset(paths_array, categories_array)
linearRegression = neuro_dll.trainLinearRegression(result_ptr, 0.0001, 50)
neuro_dll.predictLinearRegression(linearRegression, result_ptr, b"C:\Users\Esilff\Downloads\meilleurs-jeux-MOBA-pour-PC-1024x576.jpg")
# hello_string = neuro_dll.helloNeuro().decode('utf-8')