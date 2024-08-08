img_r90=cv.rotate(imgrev,cv.ROTATE_90_CLOCKWISE)
img_rc90=cv.rotate(imgrev,cv.ROTATE_90_COUNTERCLOCKWISE)
img_r180=cv.rotate(imgrev,cv.ROTATE_180)
plt.subplot(1,4,1)
plt.imshow(imgrev)
plt.axis('off')
plt.subplot(1,4,2)
plt.imshow(img_r90)
plt.axis('off')
plt.subplot(1,4,3)
plt.imshow(img_rc90)
plt.axis('off')
plt.subplot(1,4,4)
plt.imshow(img_r180)
plt.axis('off')
h,w,c=img.shape
twox=cv.resize(imgrev,None,fx=2,fy=2,interpolation=cv.INTER_LINEAR)
halfx=cv.resize(imgrev,(w//2,h//2),interpolation=cv.INTER_AREA)
nonUnf=cv.resize(imgrev,None,fx=1.5,fy=0.5)
images=[imgrev,twox,halfx,nonUnf]
titles=['Orignal','2x','0.5x','Non Uniform scaling']
for i in range(4):
    plt.subplot(2,2,i+1)
    plt.title(titles[i])
    plt.imshow(images[i])
    plt.axis('off')
    
tx=50;ty=50
h,w,c=imgrev.shape
M=np.float32([[1,0,tx],[0,1,ty]])
trans_img=cv.warpAffine(imgrev,M,(w,h))
plt.subplot(1,2,1)
plt.imshow(imgrev)
plt.axis('off')
plt.subplot(1,2,2)
plt.imshow(trans_img)
plt.axis('off')