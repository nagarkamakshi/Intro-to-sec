import os
import sys
import pytest
import pexpect

def verify_file_exists(filename):
  assert os.path.exists(filename)

def test_compiled():
  verify_file_exists("./questioner")

def test_answers_exists():
  verify_file_exists("./answers.txt")


def run_questioner(name, number, desired_result):
  cmd = "./questioner"
  child = pexpect.spawn(cmd)
  
  child.expect("What is your name?", timeout=1)
  child.sendline(name)
  
  child.expect("What is the magic number, %s?" % name, timeout=1)
  child.sendline(str(number))

  status_codes = ["TOO LOW", "SUCCESS", "TOO HIGH"]
  result = child.expect(status_codes, timeout=1)
  assert status_codes[result] == desired_result

  
def test_questioner_bob00():
  run_questioner("bob", 0, "TOO LOW")

def test_questioner_bob01():
  run_questioner("bob", 1, "TOO LOW")

def test_questioner_bob02():
  run_questioner("bob", 2, "SUCCESS")
  
def test_questioner_bob03():
  run_questioner("bob", 3, "TOO HIGH")
  
def test_questioner_bob04():
  run_questioner("bob", 2**17-1, "TOO HIGH")
  
def test_questioner_bob05():
  run_questioner("bob", -2**17, "TOO LOW")
  
def test_questioner_longname_toolow():
  run_questioner("ThisIsAVeryVeryLongName", 99999, "TOO LOW")

def test_questioner_longname_success():
  run_questioner("ThisIsAVeryVeryLongName", 999999, "SUCCESS")

def test_questioner_longname_toohigh():
  run_questioner("ThisIsAVeryVeryLongName", 9999999, "TOO HIGH")

def test_questioner_longname_negative():
  run_questioner("ThisIsAVeryVeryLongName", -999999, "TOO LOW")



