from django.contrib import admin
from django.contrib import admin 
import site 
from app.models import BlogPost


class BlogPostAdmin(admin.ModelAdmin): 
    list_display = ('title', 'timestamp') 
admin.site.register(BlogPost,BlogPostAdmin)

