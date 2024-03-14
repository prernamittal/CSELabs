from django.conf.urls import include
from django.urls import path
from app.views import archive,create_blogpost 

urlpatterns = [ 
    path('', archive, name='archive'), 
    path('app/create/', create_blogpost, name='create_blogpost'), 
 ] 
