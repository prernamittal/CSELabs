from django.urls import path
from django.conf.urls import include
from django.contrib import admin
from app import forms, views


urlpatterns = [
    path('blog/', views.archive, name='archive'),
    path('', include('app.urls')),
    path('admin/', admin.site.urls),
]
