mimg=cv.imread('messi.jpeg')
img_gray=cv.cvtColor(mimg,cv.COLOR_BGR2GRAY)
edges=cv.Canny(mimg,threshold1=100,threshold2=350)
plt.imshow(edges)



chess=cv.imread('chessboard.png')
chess_grey=cv.cvtColor(chess,cv.COLOR_BGR2GRAY)
chess_greyf=np.float32(chess_grey)
cor=cv.cornerHarris(chess_greyf,2,5,0.02)
cor=cv.dilate(cor,None)
chess[cor>0.01*cor.max()]=[255,0,0]
plt.imshow(chess)