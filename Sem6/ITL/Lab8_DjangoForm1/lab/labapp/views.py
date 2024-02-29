from django.shortcuts import render
from django.http import HttpResponse 
from .forms import RegForm 
from django.views.decorators.csrf import csrf_exempt

def index(request): 
    context = {} 
    form = RegForm(request.POST or None) 
    context['form'] = form 
    return render(request, "home.html", context) 
