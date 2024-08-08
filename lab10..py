img=cv.imread('messi.jpeg')
img_rgb=img[:,:,::-1]
avgBlur=cv.blur(img_rgb,(5,5))
gussianBlur=cv.GaussianBlur(img_rgb,(5,5),1)

images=[img_rgb,avgBlur,gussianBlur]
titles=['Orginal','Average blur','Gussian Blur']
for i in range(4):
    plt.subplot(2,3,i+1)
    plt.title(titles[i])
    plt.imshow(images[i])