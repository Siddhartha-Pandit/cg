img=cv.imread('faces.png')
imgg=cv.cvtColor(img,cv.COLOR_BGR2GRAY)
face_cascade=cv.CascadeClassifier(cv.data.haarcascades+"haarcascade_frontalface_default.xml")
faces=face_cascade.detectMultiScale(imgg,1.3,2)
for x,y,w,h in faces:
    cv.rectangle(img,(x,y),(x+w,y+h),(0,255,0),2)
img_rgb=img[:,:,::-1]
plt.imshow(img_rgb)