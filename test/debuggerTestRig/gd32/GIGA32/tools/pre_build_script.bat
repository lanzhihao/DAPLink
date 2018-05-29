::
:: DAPLink Interface Firmware
:: Copyright (c) 2009-2016, ARM Limited, All Rights Reserved
:: SPDX-License-Identifier: Apache-2.0
::
:: Licensed under the Apache License, Version 2.0 (the "License"); you may
:: not use this file except in compliance with the License.
:: You may obtain a copy of the License at
::
:: http://www.apache.org/licenses/LICENSE-2.0
::
:: Unless required by applicable law or agreed to in writing, software
:: distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
:: WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
:: See the License for the specific language governing permissions and
:: limitations under the License.
::

@set TOOLS=..\..\GIGA32\tools
@set DIR=..\..\GIGA32\
@REM  Create default version_git.h.  This is so the project 
@REM  builds if python is not installed
copy %DIR%\version_git_tmpl.txt %DIR%\version_git.h
@if %errorlevel% neq 0 exit /B %errorlevel%

@python --version 2> nul
@if %errorlevel% neq 0 echo Error: python not in PATH. If you are manually building the project, make sure to launch uVision from the python venv && exit /B %errorlevel%

@REM  Run python script to delete default version_git.h and create the real one
python %TOOLS%\pre_build_script.py
@if %errorlevel% neq 0 exit /B %errorlevel%
